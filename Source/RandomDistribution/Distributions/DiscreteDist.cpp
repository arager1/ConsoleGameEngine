
#include "DiscreteDist.hpp"

#include <algorithm>

namespace RandomDistribution
{

template <class OptionEnum>
void DiscreteDist<OptionEnum>::updateWeight(OptionEnum optionName, int optionWeight)
{
	if (optionExists(optionName))
	{
		m_optionWeights[indexOf(optionName)] = optionWeight;
	}
	else
	{
		addOption(optionName);
		m_optionWeights.push_back(optionWeight);
	}

	m_distribution.param(m_optionWeights);
}


} // namespace RandomDistribution