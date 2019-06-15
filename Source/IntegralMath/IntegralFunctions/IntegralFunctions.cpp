#include "IntegralFunctions.hpp"

#include <cmath>


namespace IntegralMath
{



int IntegralFunctions::greatestCommonFactor(int n, int m)
{
	return m == 0 ? std::abs(static_cast<double>(n)) : IntegralFunctions::greatestCommonFactor(m, n % m);
}



}