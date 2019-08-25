

#include "Fraction.hpp"

#include <vector>
#include <algorithm>


namespace RandomDistribution
{

template <typename CatagoryEnum>
CatagoryEnum CatagoricalDistribution<CatagoryEnum>::generate()
{
    // Can this be done without a temporary vector?
    std::vector<int> weightVector(m_decisionMap.size());

    std::transform(m_decisionMap.begin(), m_decisionMap.end(), weightVector.begin(),
        [](const Catagory<CatagoryEnum>& c) -> int { return c.weight(); });

    return 
        m_decisionMap
        [
            std::discrete_distribution<int>{weightVector.begin(), weightVector.end()}(m_generator)
        ]
        .catagory();
}


template <typename CatagoryEnum>
inline void CatagoricalDistribution<CatagoryEnum>::update(const CatagoryEnum& catagory, int weight)
{
    // Iterate over the decision map and update the weight of each catagory whose catagory name 
    // is equal to the given name. If the catagory name is not found, add it to the decision map 
    // with the given weight.
    if (m_decisionMap.end() == std::find_if(m_decisionMap.begin(), m_decisionMap.end(),
        [&](Catagory<CatagoryEnum> &c) -> bool
        {
            if (c.catagory() == catagory)
            {
                m_totalWeight += (weight - c.weight());
                c.setWeight(weight);
                return true;
            }
            else return false;
        }))
    {
        m_totalWeight += weight;
        m_decisionMap.push_back(Catagory<CatagoryEnum>{catagory, weight});
    }
}

template <typename CatagoryEnum>
inline void CatagoricalDistribution<CatagoryEnum>::replace(
    const CatagoryEnum& existingCatagory, 
    const CatagoryEnum& newCatagory)
{
    // Iterate over the decision map and update the catagory name of each catagory whose catagory 
    // name is equal to the given name. If the catagory name is not found, do nothing.
    auto it = std::find(m_decisionMap.begin(), m_decisionMap.end(), existingCatagory);
    if (m_decisionMap.end() != it)
    {
        *(it) = Catagory<CatagoryEnum> {newCatagory, it->weight()};
    }
}

template <typename CatagoryEnum>
inline void CatagoricalDistribution<CatagoryEnum>::remove(const CatagoryEnum& catagory)
{
    // Iterate over the decision map and remove the catagory whose catagory name is equal to 
    // the given name. If the catagory name is not found, do nothing. This is effectively 
    // accomplished by setting this catagory's weight to zero.
    std::find_if(m_decisionMap.begin(), m_decisionMap.end(),
        [&](Catagory<CatagoryEnum> &c) -> bool
        {
            if (c.catagory() == catagory)
            {
                m_totalWeight -= c.weight();
                c.setWeight(0);
                return true;
            }
            else return false;
        });
}

template <typename CatagoryEnum>
inline IntegralMath::Fraction CatagoricalDistribution<CatagoryEnum>::probability(const CatagoryEnum& catagory) const
{
    // Iterate over the decision map and calculate the probabiity of generating the catagory whose 
    // catagory name is equal to the given name. If the catagory name is not found, return 0.
    auto it = std::find_if(m_decisionMap.begin(), m_decisionMap.end(),
        [&](Catagory<CatagoryEnum> &c) -> bool { return c.catagory() == catagory; });
    if (m_decisionMap.end() != it) 
    {
        return IntegralMath::Fraction {it->weight(), m_totalWeight};
    }}


}