#pragma once
#include "Entity.h"
#include "SimulationGrid.h"

class Empty : public Entity
{
public:
    EntityType what() {
        return EntityType::EMPTY;
    }
    std::string toString() const;
    void demographics(unsigned int population[], const SimulationGrid& g);
    Entity *next(const SimulationGrid& g);
protected:
    int row;
    int col;

    void demographics(unsigned int population[], const SimulationGrid& g);
private:
};