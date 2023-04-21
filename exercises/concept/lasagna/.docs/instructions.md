# Instructions

Lucian's girlfriend is on her way home and he hasn't cooked their anniversary dinner!

In this exercise, you're going to write some code to help Lucian cook an exquisite lasagna from his favorite cookbook.

You have four tasks, all related to the time spent cooking the lasagna.

## 1. Define the expected oven time in minutes

Define the `ovenTime()` function that does not take any arguments and returns how many minutes the lasagna should be in the oven.
According to the cookbook, the expected oven time is 40 minutes:

```cpp
ovenTime();
// => 40
```

## 2. Calculate the remaining oven time in minutes

Define the `remainingOvenTime(int actualMinutesInOven)` function that takes the actual minutes the lasagna has been in the oven as an argument and returns how many minutes the lasagna still has to remain in the oven, based on the expected oven time in minutes from the previous task.

```cpp
remainingOvenTime(30);
// => 10
```

## 3. Calculate the preparation time in minutes

Define the `preparationTime(int numberOfLayers)` function that takes the number of layers you added to the lasagna as an argument and returns how many minutes you spent preparing the lasagna, assuming each layer takes you 2 minutes to prepare.

```cpp
preparationTime(2);
// => 4
```

## 4. Calculate the elapsed time in minutes

Define the `elapsedTime(int numberOfLayers, int actualMinutesInOven)` function that takes two arguments: the first argument is the number of layers you added to the lasagna, and the second argument is the number of minutes the lasagna has been in the oven. The function should return how many minutes you've worked on cooking the lasagna, which is the sum of the preparation time in minutes, and the time in minutes the lasagna has spent in the oven at the moment.

```cpp
elapsedTime(3, 20);
// => 26
```
