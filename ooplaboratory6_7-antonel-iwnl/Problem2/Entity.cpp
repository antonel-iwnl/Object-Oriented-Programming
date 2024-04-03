#include "Entity.h"
#include "EntityType.h"
#include <algorithm> // for std::fill

// This is the default constructor for the Entity class.
// It sets the row and column to -1.
Entity::Entity() {
    row = -1;
    col = -1;
}

// This is the destructor for the Entity class.
// It does nothing.
Entity::~Entity() {
}

// This method returns the EntityType of the Entity.
EntityType Entity::what() {
    return EntityType::EMPTY;
}

// This method returns a string representation of the Entity.
std::string Entity::toString() const {
    return " ";
}

// This method updates the population array.
// It does nothing.
void Entity::demographics(unsigned int population[], const SimulationGrid& g) {
}

// This method returns a pointer to the next Entity.
// It does nothing.
Entity *Entity::next(const SimulationGrid& g) {
    return nullptr;
}

// This method returns the row of the Entity.
int Entity::getRow() const {
    return row;
}

// This method returns the column of the Entity.
int Entity::getCol() const {
    return col;
}

// This method sets the row of the Entity.
void Entity::setRow(int r) {
    row = r;
}

// This method sets the column of the Entity.
void Entity::setCol(int c) {
    col = c;
}

// This method returns the number of rows in the grid.
int Entity::getRows() const {
    return SimulationGrid::getRows();
}

// This method returns the number of columns in the grid.
int Entity::getCols() const {
    return SimulationGrid::getCols();
}

// This method returns the Entity at the specified row and column.
Entity *Entity::getEntity(int row, int col) const {
    return SimulationGrid::getEntity(row, col);
}

// This method sets the Entity at the specified row and column.
void Entity::setEntity(int row, int col, Entity *e) {
    SimulationGrid::setEntity(row, col, e);
}

// This method returns the number of empty spaces in the grid.
int Entity::getEmpty() const {
    return SimulationGrid::getEmpty();
}

// This method returns the number of plants in the grid.
int Entity::getPlants() const {
    return SimulationGrid::getPlants();
}

// This method returns the number of gophers in the grid.
int Entity::getGophers() const {
    return SimulationGrid::getGophers();
}

// This method returns the number of foxes in the grid.
int Entity::getFoxes() const {
    return SimulationGrid::getFoxes();
}

// This method returns the number of entities in the grid.
int Entity::getEntities() const {
    return SimulationGrid::getEntities();
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(EntityType type) const {
    return SimulationGrid::getPopulation(type);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation() const {
    return SimulationGrid::getPopulation();
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(EntityType type, int row, int col) const {
    return SimulationGrid::getPopulation(type, row, col);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(int row, int col) const {
    return SimulationGrid::getPopulation(row, col);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(int row, int col, int radius) const {
    return SimulationGrid::getPopulation(row, col, radius);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(EntityType type, int row, int col, int radius) const {
    return SimulationGrid::getPopulation(type, row, col, radius);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(int row, int col, int radius, EntityType type) const {
    return SimulationGrid::getPopulation(row, col, radius, type);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(int row, int col, int radius, EntityType type, bool wrap) const {
    return SimulationGrid::getPopulation(row, col, radius, type, wrap);
}

// This method returns the number of entities in the grid.
int Entity::getPopulation(int row, int col, int radius, bool wrap, EntityType type) const {
    return SimulationGrid::getPopulation(row, col, radius, wrap, type);
}