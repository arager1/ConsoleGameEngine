
#include "Mathematic.hpp"


namespace Mathematic
{

namespace Information
{


static constexpr int gcfHelper(const int n, const int m) 
{
    return (isZero(m)) ? (n) : (gcfHelper(m, (n % m)));
}


constexpr int greatestCommonFactor(const int n, const int m)
{
    return (isNeg(n) && isNeg(m)) ? 
           (Constants::negOne * gcfHelper(Operations::absVal(n), Operations::absVal(m))) : 
           (gcfHelper(Operations::absVal(n), Operations::absVal(m)));
}


constexpr int factorial(const int n)
{
    return (isZero(n) || isOne(n)) ? 
           (Constants::one) : 
           (n * factorial(n - Constants::one));
}


constexpr bool additionWillOverflow(const int lhs, const int rhs)
{
    return (isPos(rhs) && (lhs > (Constants::max<int>() - rhs))) ||
           (isNeg(rhs) && (lhs < (Constants::min<int>() - rhs)));
}


constexpr bool subtractionWillOverflow(const int lhs, const int rhs)
{
    return (isNeg(rhs) && (lhs > (Constants::max<int>() + rhs))) ||
           (isPos(rhs) && (lhs < (Constants::min<int>() + rhs))); 
}


constexpr bool multiplicationWillOverflow(const int lhs, const int rhs)
{
    return (lhs > (Constants::max<int>() / rhs)) || divisionWillOverflow(lhs, rhs) ||
           (lhs < (Constants::min<int>() / rhs)) || divisionWillOverflow(rhs, lhs);
}




} // namespace Information

} // namespace Mathematic
