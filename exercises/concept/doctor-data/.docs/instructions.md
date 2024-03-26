# Instructions

You start your first day at an Australian company called "Doctor Data", which specializes in information recovery.
You aced your job interview through your knowledge of C++ and [von Neumann probes][van-neumann-probes].
As you have seen a lot of test files, your new boss wants you to recreate the respective source and header files from some test code the company has recently recovered.

In this exercise, you are going to recreate lost files.
Currently the content of the files is unusable garbage data.

~~~~exercism/note
The workflow of this concept exercise is very similar to the structure of Exercism's practice exercises.
The exercise introduction text is only one part of the specification.
The test file is your definitive guide to solving a given problem.
Due to the way C++ compilation works, the test results might not show up in the web interface until you have implemented a minimal version of every class, function and enumeration that is required by the tests.
If you receive compilation errors, they might disappear once you have addressed all tasks and tests.
~~~~

You have four tasks, all related to recovering the lost code in the header and source files.

## 1. Try to extract some first clues

You look at two recovered lines from the test files:

```cpp
heaven::Vessel bob{"Robert Johansson", 1};
heaven::Vessel will{"Riker", 2, star_map::System::BetaHydri};
```

Your sharp eye instantly recognized a namespace `heaven`.
You also see that there must be a class called `Vessel`.
The constructor can apparently be called with two or three arguments.
The first argument seems to be of type `string`, the second one is a number.
It is possible to initialize the `Vessel` class with a third argument.
The third argument comes from a `star_map` namespace.
It is an enumerator of type `System`.
You even got one of the enumerations: `BetaHydri`.

Prepare the source and header files with your discovered information.
You need two namespaces: `heaven` and `star_map`.
The `heaven` namespace has a class `Vessel`, which can be called with two or three arguments.
The `System` enum is to be placed in the `star_map` namespace and has an `EpsilonEridani` enumeration.
Keep an eye out for other enumerations, so that you can constantly update the `System` enum.

## 2. Find more details

You uncover more lines from the test:

```cpp
heaven::Vessel bob{"Robert Johansson", 1};
REQUIRE(bob.current_system == star_map::System::Sol);
REQUIRE(bob.generation == 1);
heaven::Vessel bob5 = bob.replicate("Mario");
REQUIRE(bob5.current_system == star_map::System::Sol);
REQUIRE(bob5.generation == 2);
```

The newly found test lines uncover another member function of the `Vessel` class: `replicate`.
This function receives a string and returns another `Vessel` instance.
You get an idea about the default value of the third argument of the constructor from the previous task.
You also see two public member variables of the `Vessel` class and the specification of the `replicate` member function.

Add the `replicate` function and the public member variables `current_system` and `generation` to the header and source files.

## 3. Look into the inner workings

You find some more interesting lines in the recovered test files:

```cpp
heaven::Vessel bob6{"Homer", 3, star_map::System::EpsilonEridani};
REQUIRE(bob6.busters == 0);
bob6.make_buster();
REQUIRE(bob6.busters == 1);
bool success = bob6.shoot_buster();
REQUIRE(success);
REQUIRE(bob6.busters == 0);
success = bob6.shoot_buster();
REQUIRE_FALSE(success);
```

Apparently, the `Vessel` class has a member variable `busters`, that can be changed with the two class member functions `make_buster` and `shoot_buster`.
Until other information surfaces, you take a guess that the `make_buster` function returns `void`.
As there is a test for the return value of `shoot_buster`, you assume that the function returns a `bool`.

Add the two functions and the member variable to the `Vessel` class.
Keep looking for other `System` enumerators.

## 4. Complete the picture

During your scan of the test files you find only two uncovered sections of the code:

```cpp
heaven::Vessel bob1{"Bob", 1, star_map::System::AlphaCentauri};
heaven::Vessel marv{"Marvin", 2, star_map::System::DeltaEridani};
heaven::Vessel milo{"Milo", 3, star_map::System::DeltaEridani};
heaven::Vessel howie{"Howard", 4, star_map::System::Omicron2Eridani};

REQUIRE("Bob" == heaven::get_older_bob(bob1, marv));
REQUIRE(heaven::in_the_same_system(marv, milo));
REQUIRE_FALSE(heaven::in_the_same_system(marv, howie));
```

You see two functions, that are not members of the `Vessel` class, as they are not called with an instance.
`get_older_bob` compares two `Vessel`instances and returns a `string`.
`in_the_same_system` compares two `Vessel`instances and returns a `bool`.

Implement the last missing functions from the recovered lines above.

[van-neumann-probes]: https://en.wikipedia.org/wiki/Self-replicating_spacecraft
