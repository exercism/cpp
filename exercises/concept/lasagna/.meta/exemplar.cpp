// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
int ovenTime() { return 40; }

/* RemainingOvenTime returns the remaining
minutes based on the actual minutes already in the oven.
*/
int remainingOvenTime(int actualMinutesInOven) {
    return ovenTime() - actualMinutesInOven;
}

/* PreparationTim estimates the preparation time based on the number
    of layers and an average time per layer and returns it.
*/
int preparationTime(int numberOfLayers) {
    int prepTimePerLayer{2};
    return numberOfLayers * prepTimePerLayer;
}

// ElapsedTime calculates the total time spent to create and bake the lasagna so
// far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}