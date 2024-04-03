#include <iostream>
#include "Plant.h"
#include "SimulationGrid.h"
#include "Entity.h"

std::string Plant::toString() const {
    return " ";
}

void Plant::demographics(unsigned int population[], const SimulationGrid& g) {
    population[0]++;
}

Entity *Plant::next(const SimulationGrid& g) {
    return new Plant();
}