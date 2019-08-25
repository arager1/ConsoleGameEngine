

#ifndef RANDOMDISTRIBUTION_CATAGORICALDISTRIBUTION
#define RANDOMDISTRIBUTION_CATAGORICALDISTRIBUTION

#include "Catagory.hpp"

#include <random>

namespace IntegralMath
{
    class Fraction;
}


namespace RandomDistribution
{

/// Maps a set of catagories to a discrete probability distribution.
/// Provides an abstraction layer over the raw distribution as well as various functions to 
/// modify the set of catagories and their probabilities. 
/// Template Requires: 
/// CatagoryEnum has operator==
/// CatagoryEnum has operator=
template <typename CatagoryEnum>
class CatagoricalDistribution
{
public:
    CatagoricalDistribution() = delete;

    CatagoricalDistribution(const CatagoryEnum& initialCatagory, int weight = 1)
    {
        m_decisionMap.push_back(Catagory<CatagoryEnum>{initialCatagory, weight});
    }

    /// Generates a choice of catagory based on pre-defined discrete probabilities.
    /// Reads: Member mapping from index to Catagory (m_decisionMap)
    /// Modifies: Member random number generator (m_generator)
    /// Returns: Chosen catagory (Of type CatagoryEnum)
	CatagoryEnum generate();

    /// Update the given catagory to have the given weight.
    /// If the given catagory exists in this CatagoricalDistribution, update its weight to be 
    /// the given weight. If the given catagory does not exist in this CatagoricalDistribution, 
    /// add it to this CatagoricalDistribution with given weight.
    inline void update(const CatagoryEnum& catagory, int weight = 1);

    /// Replaces an existing catagory enum with a new catagory.
    /// If the given existing catagory enum does exist in this CatagoryDistribution, update its 
    /// catagory enum to be the given, new, catagory enum. If the given existing catagory enum does 
    /// not exist in this CatagoryDistribution, does nothing.
    inline void replace(const CatagoryEnum& existingCatagory, const CatagoryEnum& newCatagory);

    /// Remove the given catagory.
    /// If the given catagory exists in this CatagoricalDistribution, remove it from this 
    /// CatagoricalDistribution. If the given catagory does not exist in this CatagoricalDistribution
    /// does nothing. 
    inline void remove(const CatagoryEnum& catagory);

    /// Return the probability of the given catagory.
    /// If the given catagory exists in this CatagoricalDistribution, return the probability of generating 
    /// this catagory with this CatagoricalDistribution. If the given catagory does not exist in this 
    /// CatagoricalDistribution return 0.
    inline IntegralMath::Fraction probability(const CatagoryEnum& catagory) const;


private:
	std::vector<Catagory<CatagoryEnum>> m_decisionMap{};
	std::mt19937 m_generator{std::random_device()()};
    int m_totalWeight {0};
};


} // namespace RandomDistribution

#include "CatagoricalDistribution.inl"

#endif // RANDOMDISTRIBUTION_CATAGORICALDISTTRIBUTION

