#include "SimulationGrid.h"

// This is the default constructor for the SimulationGrid class.
// It sets the number of rows and columns to 0.
SimulationGrid::SimulationGrid() {
    rows = 0;
    cols = 0;
}

// This is the destructor for the SimulationGrid class.
// It does nothing.
SimulationGrid::~SimulationGrid() {
}

// This method returns the number of rows in the grid.
int SimulationGrid::getRows() const {
    return rows;
}

// This method returns the number of columns in the grid.
int SimulationGrid::getCols() const {
    return cols;
}

// This method returns the Entity at the specified row and column.
Entity *SimulationGrid::getEntity(int row, int col) const {
    return grid[row][col];
}

// This method sets the Entity at the specified row and column.
void SimulationGrid::setEntity(int row, int col, Entity *e) {
    grid[row][col] = e;
}

// This method returns the number of empty spaces in the grid.
int SimulationGrid::getEmpty() const {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Entity *e = grid[r][c];
            if (e == nullptr) {
                count++;
            }
        }
    }
    return count;
}

// This method returns the number of plants in the grid.
int SimulationGrid::getPlants() const {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Entity *e = grid[r][c];
            if (e != nullptr && e->what() == EntityType::PLANT) {
                count++;
            }
        }
    }
    return count;
}

// This method returns the number of gophers in the grid.
int SimulationGrid::getGophers() const {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Entity *e = grid[r][c];
            if (e != nullptr && e->what() == EntityType::GOPHER) {
                count++;
            }
        }
    }
    return count;
}

// This method returns the number of foxes in the grid.
int SimulationGrid::getFoxes() const {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Entity *e = grid[r][c];
            if (e != nullptr && e->what() == EntityType::FOX) {
                count++;
            }
        }
    }
    return count;
}

// This method returns the number of entities in the grid.
int SimulationGrid::getEntities() const {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Entity *e = grid[r][c];
            if (e != nullptr) {
                count++;
            }
        }
    }
    return count;
}

//This method returns the population of the specified type.
int SimulationGrid::getPopulation(EntityType type) const {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Entity *e = grid[r][c];
            if (e != nullptr && e->what() == type) {
                count++;
            }
        }
    }
    return count;
}

// This method returns the population of the specified type.
int SimulationGrid::getPopulation() const {
    return getEntities();
}

// This method returns the number of entities in the grid.
int SimulationGrid::getPopulation(int row, int col, EntityType type) const {
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                Entity *e = grid[r][c];
                if (e != nullptr && e->what() == type) {
                    count++;
                }
            }
        }
    }
    return count;
}