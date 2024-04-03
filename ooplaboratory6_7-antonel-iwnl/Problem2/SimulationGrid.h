#pragma once
#define MAX_ROWS 100
#define MAX_COLS 100
// forward class declaration for Entity
class Entity;
class SimulationGrid
{
	friend class Entity;

public:
	SimulationGrid(int rows, int cols);
	~SimulationGrid();
	int getRows() const;
	int getCols() const;
	Entity *getEntity(int row, int col) const;
	void setEntity(int row, int col, Entity *e);
	int getEmpty() const;
	int getPlants() const;
	int getGophers() const;
	int getFoxes() const;
	int getEntities() const;
	int getPopulation() const;
	int getPopulation(EntityType type) const;
	int getPopulation(EntityType type, int row, int col) const;

private:
	int rows;
	int cols;
	Entity* grid[MAX_ROWS][MAX_COLS];
};

