

#ifndef RANDOMDISTRIBUTION_ABSTRACTDIST
#define RANDOMDISTRIBUTION_ABSTRACTDIST

#include <random>
#include <vector>
#include <algorithm>


namespace RandomDistribution
{

template <class OptionEnum>
class Option
{
public:
	Option(OptionEnum name) : 
		m_name{name}, m_count{0} {}

	inline bool operator==(const OptionEnum& other)
	{
		return m_name == other.m_name;
	}

	inline OptionEnum name() const
	{
		return m_name;
	}

	inline OptionEnum count() const
	{
		return m_count;
	}

	inline void increment()
	{
		m_count++;
	}

private:
	const OptionEnum m_name;
	int m_count;
};

template <class OptionEnum>
class AbstractDist
{

public:

	AbstractDist() = default;
	AbstractDist(const AbstractDist&) = default;
	AbstractDist(AbstractDist&&) = default;
	AbstractDist& operator=(const AbstractDist&) = default;
	AbstractDist& operator=(AbstractDist&&) = default;
	virtual ~AbstractDist() = default;

	virtual inline int generateIndex() const = 0;

	virtual inline OptionEnum generate() const
	{
		const int index{generateIndex()};

		m_decisionMap[index].increment();

		return m_decisionMap[index].name();
	}

	inline int getCount(const OptionEnum & optionName)
	{
		return std::find(m_decisionMap.begin(), m_decisionMap.end(), optionName)->count();
	}

protected:

	inline std::mt19937& getGenerator()
	{
		return m_generator;
	}

	inline void addOption(const OptionEnum& optionName)
	{
		m_decisionMap.push_back({optionName});
	}

	inline bool optionExists(const OptionEnum& optionName)
	{
		return std::find(m_decisionMap.begin(), m_decisionMap.end(), optionName) != m_decisionMap.end();
	}

	inline int indexOf(const OptionEnum& optionName)
	{
		return std::distance(m_decisionMap.begin(), std::find(m_decisionMap.begin(), m_decisionMap.end(), optionName));
	}

private:
	std::vector<Option<OptionEnum>> m_decisionMap{};
	std::mt19937 m_generator{std::random_device()()};
};


} // namespace RandomDistribution

#endif // RANDOMDISTRIBUTION_ABSTRACTDIST

