#include <iostream>
#include "Empty.h"
#include "SimulationGrid.h"
#include "Entity.h"

std::string Empty::toString() const {
    return " ";
}

void Empty::demographics(unsigned int population[], const SimulationGrid& g) {
    population[0]++;
}

Entity *Empty::next(const SimulationGrid& g) {
    return new Empty();
}