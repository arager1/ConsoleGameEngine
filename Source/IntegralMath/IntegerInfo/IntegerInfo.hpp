#ifndef INTEGRALMATH_INTEGERINFO_HPP
#define INTEGRALMATH_INTEGERINFO_HPP

#include <limits>

namespace IntegralMath
{


class IntegerInfo
{
public:
	static constexpr int INTMIN      {std::numeric_limits<int>::min()};
	static constexpr int INTMAX      {std::numeric_limits<int>::max()};
	static constexpr int ZERO        {0};
	static constexpr int ONE         {1};
	static constexpr int NEGATIVEONE {-1};

	static inline bool isMin      (int n) { return n == INTMIN; }
	static inline bool isMax      (int n) { return n == INTMAX; }
	static inline bool isZero     (int n) { return n == ZERO; }
	static inline bool isOne      (int n) { return n == ONE; }
	static inline bool isNegOne   (int n) { return n == NEGATIVEONE; }

	static inline bool isPositive (int n) { return n > ZERO; }
	static inline bool isNegative (int n) { return n < ZERO; }
};


}



#endif