#ifndef INTEGRALMATH_OVERFLOWDETECTOR_HPP
#define INTEGRALMATH_OVERFLOWDETECTOR_HPP


namespace IntegralMath
{


class OverflowDetector
{
public:
	static bool additionWillOverflow(int lhs, int rhs);
	static bool subtractionWillOverflow(int lhs, int rhs);
	static bool multiplicationWillOverflow(int lhs, int rhs);
};


}

#endif