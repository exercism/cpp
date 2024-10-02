# Instructions

Welcome, Engineer!
You are one of the last veterans of the Speedywagon Foundation, a secret organization that, for decades, has been battling ancient threats like the Pillar Men.
In the course of this effort, you've spent years maintaining the Foundation's technological systems, built using a mix of cutting-edge tech and aging libraries.

However, in recent times, the sensors that track Pillar Men activities are malfunctioning.
The Foundation's systems are old, and the code interacts with a legacy C++ library that cannot be updated.
Your task is to implement four core functions that monitor Pillar Men sensor activity using an old-fashioned pointer-based library.

The Foundation's operations rely on you.

## 0. The Sensor Environment (`pillar_men_sensor`)

As sensor readings can be huge, we supply a mockup _struct_ that is used in the actual library.
The code has already been implemented in the header file for you.

```cpp
struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};
```

## 1. Check Sensor Connection (`connection_check`)

Your first task is to ensure that the Pillar Men sensor is connected properly.
We can't have false alarms triggered by disconnected sensors.
You will write a function `connection_check`, which tests if the sensor's pointer is valid by checking for `nullptr`.

### Task

- Define a function that accepts a pointer a a `pillar_men_sensor` _struct_.
- The function should return `true` if the sensor pointer is not null, and `false` otherwise.

### Example

```cpp
pillar_men_sensor* sensor{nullptr};
bool isConnected = connection_check(sensor);
// isConnected => false
```

## 2. Count Activity of Sensors (`activity_counter`)

Pillar Men are lurking in the shadows, and we need to know if sensors have detected any activity.
You will write the `activity_counter` function, which takes in an array of sensors and a capacity indicating the number of sensors in the array.

### Task

- Define a function that accepts a pointer to the first element of an array and the arrays capacity.
- Use pointer arithmetic to loop through the sensor array and accumulate the activity readings.
- Return the accumulated activity.

### Example

```cpp
pillar_men_sensor sensor_array[3] = {{0}, {101}, {22}};
int totalActivity = activity_counter(sensor_array, 3);
// totalActivity => 123
```

## 3. Alarm Control (`alarm_control`)

Not every sensor should trigger an alarm unless there’s real danger.
The `alarm_control` function ensures that a sensor only triggers an alarm if its activity level is greater than 0.
This function should also check for null sensors to prevent system crashes.

### Task

- Define a function that accepts the pointer to a `pillar_men_sensor`.
- The function should first check for a `nullptr` sensor. If the sensor is `nullptr`, return `false`.
- If the sensor is valid and its activity is greater than 0, return `true`; otherwise, return `false`.

### Example

```cpp
pillar_men_sensor db{9008, "songokunoie", {7, 7, 7}};
bool alarm = alarm_control(&db);
// alarm => true
```

## 4. Checking the data for anomalies with the `uv_alarm` function

In this task, you will implement the `uv_alarm` function to determine whether an alarm should be triggered based on UV light exposure levels and sensor activity.
The `uv_alarm` function should use the provided `uv_light_heuristic` function, which operates on a vector of data and returns a value based on certain thresholds.
This is a mockup version of the complex code that will run during production, please don't change the interface.

### Task

Define the `uv_alarm` function in the `speedywagon` namespace. It should:

- Take a pointer to a `pillar_men_sensor` _struct_ as its parameter.
- Return `false` if the sensor pointer is null.
- Call the `uv_light_heuristic` function, passing the address of the sensor's `data` array.
- Return `true` if the value returned by `uv_light_heuristic` is greater than the `sensor->activity` level, otherwise return `false`.

## Wrapping Up

You’ve been entrusted with an essential task for the Speedywagon Foundation.
By testing for valid sensor connections, counting activity, and implementing alarm controls, you’ve ensured that the Foundation's battle against the Pillar Men can continue uninterrupted.

As a modern C++ engineer, you’d prefer using smart pointers, but alas, legacy code demands respect for the old ways.
The fate of humanity may rest on these pointers, so proceed carefully, and may the Hamon energy guide you.
