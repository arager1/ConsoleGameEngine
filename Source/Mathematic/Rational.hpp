
///@file Rational.hpp

#ifndef MATHEMATIC_RATIONAL
#define MATHEMATIC_RATIONAL


#include "Mathematic.hpp"

#include <string>


namespace Mathematic
{

namespace Types
{


// std::ratio fulfills this class...

class Rational
{
public:
    constexpr Rational(const int numerator = Constants::zero, const int denominator = Constants::one);

    constexpr Rational& operator+=(const Rational& rhs);
	constexpr Rational& operator-=(const Rational& rhs);
	constexpr Rational& operator*=(const Rational& rhs);
	constexpr Rational& operator/=(const Rational& rhs);

    /// Conversion
    explicit constexpr inline operator int() const {return m_numerator / m_denominator;}
    constexpr inline operator double() const {return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);}
    inline operator std::string() const {return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);}

    constexpr inline int numerator() const {return m_numerator;}
    constexpr inline int denominator() const {return m_denominator;}

private:
    int m_numerator;
    int m_denominator;

    constexpr void reduce();
    void verify();
};



inline constexpr Rational operator+(Rational lhs, const Rational& rhs)
{
	lhs += rhs;
	return lhs;
}

inline constexpr Rational operator-(Rational lhs, const Rational& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline constexpr Rational operator*(Rational lhs, const Rational& rhs)
{
	lhs *= rhs;
	return lhs;
}

inline constexpr Rational operator/(Rational lhs, const Rational& rhs)
{
	lhs /= rhs;
	return lhs;
}

inline constexpr bool operator==(const Rational& lhs, const Rational& rhs)
{
    return (Mathematic::Information::areEqual(lhs.numerator(), rhs.numerator())) && 
           (Mathematic::Information::areEqual(lhs.denominator(), rhs.denominator()));
}

inline constexpr bool operator<(const Rational& lhs, const Rational& rhs)
{
    return double{lhs} < double{rhs};
}

inline constexpr bool operator!=(const Rational& lhs, const Rational& rhs) { return !operator==(lhs, rhs); }

inline constexpr bool operator>(const Rational& lhs, const Rational& rhs) { return operator<(rhs, lhs); }

inline constexpr bool operator<=(const Rational& lhs, const Rational& rhs) { return !operator>(lhs, rhs); }

inline constexpr bool operator>=(const Rational& lhs, const Rational& rhs) { return !operator<(lhs, rhs); }


} // namespace Types

} // namespace Mathemtic

#endif
