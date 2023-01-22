#include "lasagna_master.h"

namespace lasagna_master {
    // ovenTime returns the amount in minutes that the lasagna should stay in the oven.
    int Lasagna::ovenTime() {
        // TODO: Return the correct time.
        return 0;
    }

    /* PreparationTim estimates the preparation time based on the number
        of layers and an average time per layer and returns it.
    */
    int Lasagna::preparationTime(int numberOfLayers) {
        // TODO: Calculate and return the preparation time with the `numberOfLayers`.
        return 0; }

    /* RemainingOvenTime returns the remaining
    minutes based on the actual minutes already in the oven.
    */
    int Lasagna::remainingOvenTime(int actualMinutesInOven) {
        // TODO: Calculate and return the remaining in the oven based on the time `actualMinutesInOven` the Lasagna has already spend there.
        return 0;
        }

    // ElapsedTime calculates the total time spend to create and bake the lasagna so far.
    int Lasagna::elapsedTime(int numberOfLayers, int actualMinutesInOven) {
        // TODO: Calculate and return the time total time so far.
        return 0;
        }
} // namespace lasagna_master
