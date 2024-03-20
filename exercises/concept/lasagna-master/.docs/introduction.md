# Introduction

## Terminology

You have already used and written C++ functions in a couple of concepts.
It is time to get technical.
The code snippet below shows the most common terms for easy reference.
As C++ ignores whitespace, the formatting has been changed to put each element on a single line.

```cpp
// Function declaration:
bool                                              // Return type
admin_detected(string user, string password)      // Type signature
;                                                 // Don't forget the ';' for the declaration

// Function definition:
bool                                              // Return type
admin_detected                                    // Function name
(string user, string password)                    // Parameter list
{ return user == "admin" && password == "1234"; } // Function body
```
~~~~exercism/advanced
The declaration works like a note to the compiler, that there is a function of that name, return type and parameter list.
The code will not work, if the definition is missing.
Declarations are optional, they are needed if you use the function before its definiton.
Declarations can solve problems like cyclic references and they can be used to separate the interface from the implementation.
~~~~

## The const qualifier

Sometimes you want to make sure that values cannot be changed after they have been initialized.
C++ uses the `const` keyword as a qualifier for constants.

```cpp
const int number_of_dragon_balls{7};
number_of_dragon_balls--; // compilation error
```

~~~~exercism/note
You will often see constants written in _UPPER_SNAKE_CASE_.
It is recommened to reserve this casing for macros, if there is no other convention.
~~~~

If you try to change a constant variable after it has been set, your code will not compile.
This helps to avoid unintended changes but also opens up optimization possibilities for the compiler.
As a human, it is also easier to reason about the code, if you know that certain parts will not be affected.

You can also have `const` as a qualifier for function parameters.

```cpp
string guess_number(const int& secret, const int& guess) {
    if (secret < guess) return "lower.";
    if (secret > guess) return "higher.";
    return "exact!";
}
```

When you pass a `const` reference to the function, you can be sure that it will be left unchanged.
You will often see `const` references for objects that might be costly to copy, like longer strings.
A third use-case for the `const` qualifier are member functions that do not change the instance of a class.

```cpp
class Stubborn {
    public:
    Stubborn(string reply) {
        response = reply;
    }
    string answer(const string& question) const {
        if (question.lenghth() == 0) { return "";}
        return response;
    }
    private:
    string response{};
};
```

The `Stubborn` member function `answer` uses a `const string&` reference as a parameter.
This avoids a copy operation from the original object that was passed to the function.

## Function overloading

Multiple functions can have the same name if the parameter list is different.
That is called function overloading and it is usually done if these functions perform very similar tasks.

The function header without the return type is the function's __type signature__.
A change in the type signature results in a new function.

The `play_sound` example has six different overloads to accommodate different scenarios:

```cpp
// different argument types:
void play_sound(char note);         // C, D, E, ..., B
void play_sound(string solfege);    // do, re, mi, ..., ti
void play_sound(int jianpu);        // 1, 2, 3, ..., 7

// different number of arguments:
void play_sound(string solfege, double duration);

// different qualifiers:
void play_sound(vector<string>& solfege);
void play_sound(const vector<string>& solfege);
```

~~~~exercism/advanced
The type signature is defined by the function's name, the number of parameters, their types, and their qualifiers (but not their names).
The return type is explicitly not part of the type signature and you will get compilation errors if you have two functions that only differ in their return type.
The compiler will complain because it is not clear which of the two should be used.
~~~~

## Default arguments

Some functions can get very lengthy and many of its calls might use the same values for most of the parameters.
The repetition in those calls can be avoided with default arguments.

```cpp
void record_new_horse_birth(string name, int weight, string color="brown-ish", string dam="Alruccaba", string sire="Poseidon");

record_new_horse_birth("Urban Sea", 130); // color will be brown, dam "Alruccabam", sire "Poseidon"
record_new_horse_birth("Highclere", 175, "off-white", "Fall Aspen");   // sire will be "Poseidon"
```

As the function declaration is often read before the definition, it is the better place to set the default arguments.
If one parameter has a default declaration, all the parameters to its right need a default declaration as well.
Sometimes complicated function overloads can be refactored to fewer functions with default arguments to improve maintainability.
