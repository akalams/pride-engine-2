#pragma once
#include <vector>


struct Transform
{
	float x, y;
};

struct View
{
	char symbol;
};

template <typename T>
class ComponentSet
{
public:
    ComponentSet() {};
    ComponentSet(const size_t size) : mComponents(size) {}

    T getComponent(size_t entityID) const
    {
        if (entityID >= mComponents.size())
        {
            throw std::out_of_range("Entity ID out of range in ComponentSet");
        }
        return mComponents[entityID];
    }
    void addComponent(const T& component)
    {
        mComponents.push_back(component);
    }
    size_t size() const
    {
        return mComponents.size();
    }

private:
    std::vector<T> mComponents;
};