#include "Entity.h"
#include "EntityType.h"
#include <algorithm> // for std::fill

class Animal : public Entity
{
    public:
        Animal();
        ~Animal();
        EntityType what();
        std::string toString() const;
        void demographics(unsigned int population[], const SimulationGrid& g);
        Entity *next(const SimulationGrid& g);
    protected:
        int row;
        int col;
    private:
};