# Instructions

In this exercise you'll be automating some timing tasks for your weekly lasagna cooking session.
As you vary your recipes often, you want to know how much time you have to spend for different
lasagna types.

You want to write a program to show you the time the lasagna has to be in the oven, how much time 
you will have preparing and also how much time is left until the lasagna is ready.

All you lasagna recipes need `40` minutes in the oven and the preparation takes `2` minutes per layer.

## 1. Get the time that is spend baking.

Implement the `lasagna::ovenTime` method to return a the minutes the lasagna has to stay in the oven.

## 2. Get the preparation time.

Implement the `lasagna::preparationTime` method to return the preparation time based on the number of layers.

```cpp
lasagna::preparationTime(11)
// => 22
```

## 3. Calculate the time left in the oven

Implement the `lasagna::remainingOvenTime` method that takes the number of minutes the lasagna has already spend in the oven and 
returns the remaining minutes.

```cpp
`lasagna::remainingOvenTimet(4)
// => 36
```

## 4. Calculate the total time spend for the lasagna

Implement the `lasagna::elapsedTime` method that takes the number of layers and the number of minutes the lasagna has already spend in the oven and returns the total time spend preparing and waiting for the oven to finish.

```cpp
`lasagna::elapsedTime(40, 20)
// => 100
```