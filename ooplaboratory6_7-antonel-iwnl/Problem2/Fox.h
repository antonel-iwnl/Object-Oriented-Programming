#include "Entity.h"
#include "SimulationGrid.h"

class Fox : public Entity
{
public:
    EntityType what() {
        return EntityType::FOX;
    }
    std::string toString() const;
    void demographics(unsigned int population[], const SimulationGrid& g);
    Entity *next(const SimulationGrid& g);

private:
};
