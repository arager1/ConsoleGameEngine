
#include "ObjectFactory.hpp"

#include <algorithm>

namespace Serial
{

ObjectFactory& ObjectFactory::instance()
{
    static ObjectFactory instance;
    return instance;
}

template<typename ClassType>
void ObjectFactory::registerClass(const std::string& className)
{
    m_factory[className] = [](){ return std::move(std::make_unique<ClassType>()); };
}

std::unique_ptr<Instantiatable> ObjectFactory::createClass(const std::string& className)
{
    return (m_factory.end() != m_factory.find(className)) ? m_factory[className]() : std::unique_ptr<Instantiatable> {};
}

}

