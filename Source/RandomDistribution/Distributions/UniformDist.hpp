#ifndef RANDOMDISTRIBUTION_UNIFORMDIST
#define RANDOMDISTRIBUTION_UNIFORMDIST

#include "AbstractDist.hpp"

namespace RandomDistribution
{

template <class OptionEnum>
class UniformDist : public AbstractDist<OptionEnum>
{
public:
	UniformDist() = default;
	UniformDist(const UniformDist&) = default;
	UniformDist(UniformDist&&) = default;
	UniformDist& operator=(const UniformDist&) = default;
	UniformDist& operator=(UniformDist&&) = default;
	~UniformDist() = default;

	void setWeight(OptionEnum name, int weight);

	OptionEnum generate() const override;

private:

};


} // namespace RandomDistribution

#endif // RANDOMDISTRIBUTION_UNIFORMDIST

