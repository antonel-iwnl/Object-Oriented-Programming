#include <iostream>
#include "Fox.h"
#include "SimulationGrid.h"
#include "Entity.h"

std::string Fox::toString() const {
    return "F";
}

void Fox::demographics(unsigned int population[], const SimulationGrid& g) {
    population[2]++;
}

Entity *Fox::next(const SimulationGrid& g) {
    return new Fox();
}