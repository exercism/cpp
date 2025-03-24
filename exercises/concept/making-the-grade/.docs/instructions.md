# Instructions

You're a teaching assistant correcting student exams.
Keeping track of results manually is getting both tedious and mistake-prone.
You decide to make things a little more interesting by putting together some functions to count and calculate results for the class.

## 1. Rounding Scores

While you can give "partial credit" on exam questions, overall exam scores have to be `int`s.
So before you can do anything else with the class scores, you need to go through the grades and turn any `double` scores into `int`s.

Create the function `round_down_scores()` that takes a `vector` of `student_scores`.
The schools' requested rounding is a truncation.
Lucky for you, C++ can cast one type into another with `static_cast`.
The `static_cast` conversion from `double` to `int` cuts off any digit after the decimal.
This function should take the input `vector` and `return` a new vector with all the scores converted to `int`s.

```cpp
std::vector<double> student_scores {90.33, 40.5, 55.44, 70.05, 30.55, 25.45, 80.45, 95.3, 38.7, 40.3};
round_down_scores(student_scores)
// => {90, 40, 55, 70, 30, 25, 80, 95, 38, 40}
```

There are other methods which achieve the same result, but a _cast_ is a common sight.

```cpp
int new_PI{static_cast<int>(3.14) + static_cast<int>(0.001592653589)};
// new_PI is 3.
```

## 2. Non-Passing Students

As you were grading the exam, you noticed some students weren't performing as well as you'd hoped.
But you were distracted, and forgot to note exactly _how many_ students.

Create the function `count_failed_students()` that takes a `vector` of `student_scores`.
This function should count up the number of students who don't have passing scores and return that count as an integer.
A student needs a score greater than **40** to achieve a passing grade on the exam.

```cpp
count_failed_students({90,40,55,70,30,25,80,95,38,40});
// => 5
```

## 3. Calculating Letter Grades

The teacher you're assisting likes to assign letter grades as well as numeric scores.
Since students rarely score 100 on an exam, the "letter grade" lower thresholds are calculated based on the highest score achieved, and increment evenly between the high score and the failing threshold of **<= 40**.

Create the function `letter_grades()` that takes the "highest" score on the exam as a parameter, and returns an `array` (not a vector) of lower score thresholds for each "American style" grade interval: `["D", "C", "B", "A"]`.

```cpp
/*Where the highest score is 100, and failing is <= 40.
       "F" <= 40
 41 <= "D" <= 55
 56 <= "C" <= 70
 71 <= "B" <= 85
 86 <= "A" <= 100
*/

letter_grades(100);
// => {41, 56, 71, 86}


/*Where the highest score is 88, and failing is <= 40.
       "F" <= 40
 41 <= "D" <= 52
 53 <= "C" <= 64
 65 <= "B" <= 76
 77 <= "A" <= 88
*/

letter_grades(88);
// => {41, 53, 65, 77}
```

## 4. Matching Names to Scores

You have exam scores in descending order, and the respective student names (sorted in the order of their exam scores).
You would like to match each student's name with their exam score and print out an overall class ranking.

Create the function `student_ranking()` with parameters `student_scores` and `student_names`.
Match each student name on the student_names `vector` with their score from the student_scores `vector`.
You can assume each argument `vector` is sorted from highest score(er) to lowest score(er).
The function should return a `vector` of strings with the format `<rank>. <student name>: <student score>`.

```cpp
std::vector<int> student_scores {100, 99, 90, 84, 66, 53, 47};
std::vector<std::string> student_names {"Joci", "Sara","Kora","Jan","Indra","Bern", "Fred"};
student_ranking(student_scores, student_names)
// =>
//  {"1. Joci: 100", "2. Sara: 99", "3. Kora: 90", "4. Jan: 84", "5. Indra: 66", "6. Bern: 53", "7. Fred: 47"}
```

## 5. A "Perfect" Score

Although a "perfect" score of 100 is rare on an exam, it is interesting to know if at least one student has achieved it.

Create the function `perfect_score()` with parameters `student_scores` and `student_names`.
The lists are the same as in task 5.
The function should `return` _the first_ `<name>` (as a string) of the student who scored 100 on the exam.

If no 100 scores are found, an empty string `""` should be returned.

```cpp
perfect_score({"Nur", "Tony", "Fatima"}, {90, 80, 100});
// => "Fatima"

perfect_score({"Nur", "Tony"}, {90, 80});
// => ""
```
