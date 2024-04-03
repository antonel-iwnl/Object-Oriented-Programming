#include <iostream>
#include "Gopher.h"
#include "SimulationGrid.h"
#include "Entity.h"

std::string Gopher::toString() const {
    return "G";
}

void Gopher::demographics(unsigned int population[], const SimulationGrid& g) {
    population[1]++;
}

Entity *Gopher::next(const SimulationGrid& g) {
    return new Gopher();
}