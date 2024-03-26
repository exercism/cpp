#include <stdexcept>

#include "two_bucket.h"

two_bucket::measure_result two_bucket::measure(int bucket1_capacity,
                                               int bucket2_capacity,
                                               int target_volume,
                                               bucket_id start_bucket) {
    if (start_bucket == bucket_id::two) {
        auto result = measure(bucket2_capacity, bucket1_capacity, target_volume,
                              bucket_id::one);
        result.goal_bucket = (result.goal_bucket == bucket_id::one)
                                 ? bucket_id::two
                                 : bucket_id::one;
        return result;
    }

    if (target_volume == 0) return {0, bucket_id::one, 0};
    if (target_volume == bucket1_capacity) return {1, bucket_id::one, 0};
    if (target_volume == bucket2_capacity)
        return {2, bucket_id::two, bucket1_capacity};

    int num_steps = 0;
    int volume1 = 0;
    int volume2 = 0;
    while (volume1 != 0 || volume2 != bucket2_capacity) {
        num_steps += 2;
        if (volume1 == 0)
            volume1 = bucket1_capacity;  // fill(one)
        else
            volume2 = 0;  // empty(two)

        // pour(one, two)
        if (volume1 + volume2 <= bucket2_capacity) {
            volume2 += volume1;
            volume1 = 0;
            if (volume2 == target_volume) return {num_steps, bucket_id::two, 0};
        } else  // if volume1 + volume2 > bucket2_max
        {
            volume1 -= bucket2_capacity - volume2;
            volume2 = bucket2_capacity;
            if (volume1 == target_volume)
                return {num_steps, bucket_id::one, bucket2_capacity};
        }
    }
    throw std::invalid_argument("impossible");
}
