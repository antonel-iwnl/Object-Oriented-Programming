#pragma once
#include "EntityType.h"
#include "SimulationGrid.h"

class enum EntityType {
	Animal,
	EMPTY,
	PLANT,
	GOPHER,
	FOX
}

class Entity
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