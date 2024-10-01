#include "speedywagon.h"

namespace speedywagon {

    bool connection_check(pillar_men_sensor* sensor) {
        return sensor != nullptr;
    }

    int activity_counter(pillar_men_sensor* sensor_array, int capacity) {
        int sum{};
        for (int i{}; i < capacity; ++i) {
            sum += (sensor_array+i)->activity;
        }
        return sum;
    }

    bool alarm_control(pillar_men_sensor* sensor) {
        if (sensor == nullptr) return false;
        return sensor->activity > 0;
    }

}  // namespace speedywagon
