#ifndef INTEGRALMATH_INTEGRALFUNCTIONS_HPP
#define INTEGRALMATH_INTEGRALFUNCTIONS_HPP

#include "IntegerInfo.hpp"

namespace IntegralMath
{


class IntegralFunctions
{
public:
	static inline void invert(int& nRef) { nRef *= -1; }
	static inline bool isFactor(int n, int m) { return IntegerInfo::isZero(m % n); }
	static int greatestCommonFactor(int n, int m);
};


}



#endif