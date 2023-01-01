#include <iostream>

class Entity
{
private:
    std::string entityId;
    unsigned health;
    double positionX;

    const int constant;
    int &reference;

public:
    // using constructor initialize list to initialize const and reference
    Entity::Entity(const std::string &id, unsigned h, double p, int i = 1) : entityId(id), health(h), positionX(p), constant(i), reference(i) {} 
    Entity::~Entity();
    std::string GetId() const
    {
        return entityId;
    }
    Entity &combine(const Entity &);
    double SmoothPos() const;
};

Entity::~Entity()
{
}

Entity &Entity::combine(const Entity &entity)
{
    this->health += entity.health;
    return *this;
}
int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}