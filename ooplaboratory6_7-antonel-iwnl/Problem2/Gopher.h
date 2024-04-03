#include "Entity.h"
#include "SimulationGrid.h"

class Gopher : public Entity
{
public:
    EntityType what() {
        return EntityType::GOPHER;
    }
    std::string toString() const;
    void demographics(unsigned int population[], const SimulationGrid& g);
    Entity *next(const SimulationGrid& g);
private:
};