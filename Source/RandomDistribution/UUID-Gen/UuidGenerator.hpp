
#ifndef RANDOMDISTRIBUTION_UUIDGENERATOR
#define  RANDOMDISTRIBUTION_UUIDGENERATOR

#include <sstream>

namespace RandomDistribution
{

class UniqueID
{
public:
    UniqueID(std::string val) : m_val{val} {}

private:
    std::string m_val {};
}

class UniqueIDGenerator
{
public:
    UniqueIDGenerator() = delete;

    static UniqueID generate();

private:

};

}

#endif
