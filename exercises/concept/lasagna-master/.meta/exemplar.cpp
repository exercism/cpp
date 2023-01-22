#include "lasagna_master.h"

namespace lasagna_master {
    // ovenTime returns the amount in minutes that the lasagna should stay in the oven.
    int lasagna::ovenTime() {
        return 40;
    }

    /* PreparationTim estimates the preparation time based on the number
        of layers and an average time per layer and returns it.
    */
    int lasagna::preparationTime(int numberOfLayers) {
        int prepTimePerLayer = 2;
        return numberOfLayers*prepTimePerLayer; 
    }

    /* RemainingOvenTime returns the remaining
    minutes based on the actual minutes already in the oven.
    */
    int lasagna::remainingOvenTime(int actualMinutesInOven) {
        return ovenTime()-actualMinutesInOven;
    }

    // ElapsedTime calculates the total time spend to create and bake the lasagna so far.
    int lasagna::elapsedTime(int numberOfLayers, int actualMinutesInOven) {
        return preparationTime(numberOfLayers) + actualMinutesInOven;
        }
} // namespace lasagna_master
