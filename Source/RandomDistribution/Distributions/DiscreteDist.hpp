#ifndef RANDOMDISTRIBUTION_DISCRETEDIST
#define RANDOMDISTRIBUTION_DISCRETEDIST

#include "AbstractDist.hpp"

#include <vector>
#include <random>


namespace RandomDistribution
{

template <class OptionEnum>
class DiscreteDist : public AbstractDist<OptionEnum>
{
public:
	DiscreteDist() = default;
	DiscreteDist(const DiscreteDist&) = default;
	DiscreteDist(DiscreteDist&&) = default;
	DiscreteDist& operator=(const DiscreteDist&) = default;
	DiscreteDist& operator=(DiscreteDist&&) = default;
	~DiscreteDist() = default;

	virtual inline void updateWeight(OptionEnum optionName, int optionWeight);

	virtual inline int generateIndex() const override
	{
		return m_distribution(AbstractDist<OptionEnum>::m_generator);
	}

private:
	std::discrete_distribution<int> m_distribution{};
	std::vector<int> m_optionWeights{};
};


} // namespace RandomDistribution

#endif // RANDOMDISTRIBUTION_DISCRETEDIST

