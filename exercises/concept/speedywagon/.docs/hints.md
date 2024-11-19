# Hints

## General

- Pay close attention to pointer syntax.
  You will be using `*` (dereference operator) and `->` (member access through pointer).
- Make sure to check for null pointers (`nullptr`) where necessary to avoid accessing invalid memory.
- You can run the tests even if your code isn't complete; a rough structure is enough to see test results.
- All functions used by the tests must be declared in the header file.
- If your program crashes or behaves unexpectedly, it's often due to null pointer dereferencing.
  Double-check that you handle `nullptr` properly.
- When using pointer arithmetic, ensure that you stay within the bounds of the sensor array.
  Going beyond the array's capacity can lead to memory issues.

## 1. Check Sensor Connection (`connection_check`)

- The task is mainly about verifying whether a pointer is null or not.
- Use the comparison operator `!=` to check if a pointer is valid.
- If you're unsure whether you're checking the pointer correctly, think about what `nullptr` represents (the absence of a valid memory address).


## 2. Count Activity of Sensors (`activity_counter`)

- You need to iterate over the array of sensors.
  An array in C++ can be treated as a pointer to its first element.
- Use pointer arithmetic (`sensor_array + i`) to access the sensor at index `i`.
- The `->` operator is used to access a member of the struct through a pointer.

### Example

```cpp
int sum = (sensor_array + i)->activity; // Access activity using pointer arithmetic
```

## 3. Alarm Control (`alarm_control`)

- First, check if the pointer is null before accessing the sensor.
- Use the `->` operator to access the `activity` member of the `pillar_men_sensor` struct.
- Think carefully about what should happen if the sensor's activity level is `0`.
  Should the alarm trigger?

## 4. Checking the data for anomalies with the `uv_alarm` function

- Use the `&` operator to pass a pointer to the sensor's data array into the `uv_light_heuristic` function.
- Ensure you correctly check for a null pointer before accessing the sensor's data.
- Compare the result of `uv_light_heuristic` with the sensor's `activity` value to determine if the alarm should trigger.
