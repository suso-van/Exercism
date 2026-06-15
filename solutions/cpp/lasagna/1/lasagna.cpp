// ovenTime returns the amount in minutes that the lasagna should stay in the oven.
int ovenTime() {
    // The recipe dictates the lasagna stays in the oven for 40 minutes.
    return 40;
}

/* remainingOvenTime returns the remaining
    minutes based on the actual minutes already in the oven.
*/
int remainingOvenTime(int actualMinutesInOven) {
    // Subtract the time already spent in the oven from the total oven time.
    // We can call our own ovenTime() function here!
    return ovenTime() - actualMinutesInOven;
}

/* preparationTime returns an estimate of the preparation time based on the
    number of layers and the necessary time per layer.
*/
int preparationTime(int numberOfLayers) {
    // Each layer takes 2 minutes to prepare.
    return numberOfLayers * 2;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    // Total elapsed time = preparation time + time spent in the oven so far.
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}