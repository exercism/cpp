#!/usr/bin/python3

from __future__ import annotations
import argparse
import os
import shutil
import json
import subprocess
import re
import requests

class ExerciseBuilder:
  
  def __init__(self, slug, authors, folder):
    self.slug = slug
    self.snake_cased_slug = re.sub('-', '_', slug).lower()
    self.authors = authors
    self.folder = folder

    self.bin_dir = os.path.dirname(os.path.abspath(__file__))
    self.practice_exercise_dir = os.path.normpath(os.path.join(self.bin_dir, "..", "exercises", "practice", self.slug))
  
  def make_files_from_templates(self, infile_path: str, outfile_path: str, replacements) -> bool:
      with open(infile_path) as infile, open(outfile_path, 'w') as outfile:
          for line in infile:
              for src, target in replacements.items():
                  line = line.replace(src, target)
              outfile.write(line)

  def confirm(self, message: str, default: Optional[bool] = None) -> bool:
      """Ask the user for confirmation on the terminal.

      :param message: the question to print
      :param default: the default answer if user just presses Enter
      :returns: the answer of the user
      """
      keys = ['n', 'y']
      get_key = lambda v: (str.lower,str.upper)[v == default](keys[v])
      prompt = f"{message} ({get_key(True)}/{get_key(False)}) "
      while True:
          answer = input(prompt)
          answer = answer.lower()
          if answer == keys[True]:
              return True
          if answer == keys[False]:
              return False
          if answer == '' and default is not None:
              return default
          print('Please answer with "y" for yes or "n" for no.')
          
  def setup_general_exercism_layout(self):
    completed_process = subprocess.run([os.path.join(self.bin_dir, "configlet"), "sync", "-e", self.slug, "-u", "-y", "--tests", "include", "--docs", "--filepaths", "--metadata"])
    completed_process.check_returncode()
    
  def setup_cpp_specific_files(self):
    os.makedirs(os.path.join(self.practice_exercise_dir, "test"), exist_ok=True)

    files_to_be_templated = {
        'TEMPLATE.cpp': self.snake_cased_slug + '.cpp',
        'TEMPLATE.h': self.snake_cased_slug + '.h',
        'TEMPLATE_test.cpp': self.snake_cased_slug + '_test.cpp',
        os.path.join('.meta', 'example.h'): os.path.join('.meta', 'example.h'),
        os.path.join('.meta', 'example.cpp'): os.path.join('.meta', 'example.cpp')
    }
    template_replacements = {'TEMPLATE': self.snake_cased_slug}
    for infilepath, outfilepath  in files_to_be_templated.items():
        self.make_files_from_templates(os.path.join(self.bin_dir,'exercise_template_files', infilepath), os.path.join(self.practice_exercise_dir, outfilepath), template_replacements)

    files_to_be_copied = [
        os.path.join('test', 'catch.hpp'),
        os.path.join('test', 'tests-main.cpp'),
        'CMakeLists.txt',
    ]
    for filepath in files_to_be_copied:
        shutil.copyfile(os.path.join(self.bin_dir, 'exercise_template_files', filepath), os.path.join(self.practice_exercise_dir, filepath))
        
  def configure_config_json(self):
    with open(os.path.join(self.practice_exercise_dir, '.meta', 'config.json'), "r+") as jsonFile:
        data = json.load(jsonFile)

        data["authors"] = self.authors
        data["files"]["example"] = ['.meta/example.cpp', '.meta/example.h']

        jsonFile.seek(0)  # rewind
        json.dump(data, jsonFile, indent=2)
        
  def get_arguments_from_test_case(self, case):
    return list(map(self.quote_strings, case["input"].values()))
  
  def quote_strings(self, str):
    if not isinstance(str, (int, float)):
      return f'"{str}"'
    else:
      return format(str)
        
  def populate_test_files_from_problem_spec(self):
    canonical_url = "https://raw.githubusercontent.com/exercism/problem-specifications/main/exercises/" + self.slug + "/canonical-data.json"
    canonical_data = json.loads(requests.get(canonical_url).text)
    
    write_data = []
    if 'comments' in canonical_data:
      comment = "/*\n" + "\n".join(canonical_data['comments']) + "\n*/"
      write_data.append(comment)
    
    stop_macro_written = False
    
    for top_case in canonical_data['cases']:
      if 'cases' in top_case:
        cases = top_case['cases']
      else:
        cases = [top_case]
      
      for case in cases:
        require_str = f'REQUIRE({self.quote_strings(case["expected"])} == {self.snake_cased_slug}::{case["property"]}({", ".join(self.get_arguments_from_test_case(case))}));'
        
        test_str = (f'TEST_CASE("{case["description"]}", "[{case["uuid"]}]") {{\n'   \
                    f'\t{require_str}\n' \
                  '}')
        write_data.append(test_str)
        if not stop_macro_written:
          write_data.append('#if defined(EXERCISM_RUN_ALL_TESTS)')
          stop_macro_written = True
    
    write_data.append("#endif")
    with open(os.path.join(self.practice_exercise_dir, self.snake_cased_slug + '_test.cpp'), "a") as testfile:
      for entry in write_data:
        testfile.write("\n\n" + entry)
      testfile.write("\n")
  
  def make_cmake_folders(self):
    if not self.folder:
      return
    os.makedirs(os.path.join(self.practice_exercise_dir, self.slug, 'test'), exist_ok=True)
    
    files_to_be_copied = [
        os.path.join('test', 'catch.hpp'),
        os.path.join('test', 'tests-main.cpp'),
        'CMakeLists.txt',
        self.snake_cased_slug + '.h',
        self.snake_cased_slug + '.cpp',
        self.snake_cased_slug + '_test.cpp',
    ]
    for filepath in files_to_be_copied:
        shutil.copyfile(os.path.join(self.practice_exercise_dir, filepath), os.path.join(self.practice_exercise_dir, self.slug, filepath))
        
    with open(os.path.join(self.practice_exercise_dir, '.gitignore'), "a") as gitfile:
      gitfile.write(self.slug + "\n.gitignore")
    
        
  def run(self):        
    self.setup_general_exercism_layout()
    self.setup_cpp_specific_files()
    self.configure_config_json()
    self.populate_test_files_from_problem_spec()
    self.make_cmake_folders()
        
          
          

parser = argparse.ArgumentParser(description='Create an exercise from the problem specs and add C++ file skeletons.')
parser.add_argument('slug', metavar='exercise-slug', type=str,
                    help='slug of an exercise in kebab-case (e.g. all-your-base)')
parser.add_argument('author', metavar='author', type=str,
                    help='GitHub id of the author to populate config files')
parser.add_argument('--testing-folder', dest='folder', action='store_true', help='create a nested folder for testing')
args = parser.parse_args()

builder = ExerciseBuilder(args.slug, [args.author], args.folder)
builder.run()