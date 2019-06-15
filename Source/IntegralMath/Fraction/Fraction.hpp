#ifndef INTEGRALMATH_FRACTION_HPP
#define INTEGRALMATH_FRACTION_HPP

#include "IntegerInfo.hpp"

#include <string>


namespace IntegralMath
{



class Fraction
{

public:

	enum class FractionTerm { Numerator = 0, Denominator = 1 };

	Fraction(int numerator = IntegerInfo::ZERO, int denominator = IntegerInfo::ONE);
	Fraction(const Fraction&) = default;
	Fraction(Fraction&&) = default;
	Fraction& operator=(const Fraction&) = default;
	Fraction& operator=(Fraction&&) = default;
	~Fraction() = default;

	Fraction &operator+=(const Fraction& rhs);
	Fraction &operator-=(const Fraction& rhs);
	Fraction &operator*=(const Fraction& rhs);
	Fraction &operator/=(const Fraction& rhs);

	inline int get(FractionTerm fractionterm) const
	{
		switch (fractionterm)
		{
		case FractionTerm::Numerator:
			return m_numerator;
		case FractionTerm::Denominator:
			return m_denominator;
		default:
			return IntegerInfo::ZERO;
		}
	}

	explicit inline operator int() const
	{
		return m_numerator / m_denominator;
	}

	explicit inline operator double() const
	{
		return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
	}

	explicit inline operator std::string() const
	{
		return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);
	}


private:
	int m_numerator;
	int m_denominator;

	inline void verify(const std::string& context = "")
	{
		if (IntegerInfo::isZero(m_denominator))
			throw std::runtime_error(
				"IntegralMath::Fraction denominator became 0" + 
				( (context == "") ? "" : (" during " + context) ) );
	}

	void reduce();

};

inline Fraction operator+(Fraction lhs, const Fraction& rhs)
{
	lhs += rhs;
	return lhs;
}

inline Fraction operator-(Fraction lhs, const Fraction& rhs)
{
	lhs -= rhs;
	return lhs;
}

inline Fraction operator*(Fraction lhs, const Fraction& rhs)
{
	lhs *= rhs;
	return lhs;
}

inline Fraction operator/(Fraction lhs, const Fraction& rhs)
{
	lhs /= rhs;
	return lhs;
}

inline bool operator==(const Fraction& lhs, const Fraction& rhs)
{
	return ( lhs.get(Fraction::FractionTerm::Numerator) == 
			 rhs.get(Fraction::FractionTerm::Numerator) ) && 
		   ( lhs.get(Fraction::FractionTerm::Denominator) == 
		   	 rhs.get(Fraction::FractionTerm::Denominator) );
}

inline bool operator!=(const Fraction& lhs, const Fraction& rhs) { return !operator==(lhs, rhs); }

inline bool operator<(const Fraction& lhs, const Fraction& rhs)
{
	return static_cast<double>(lhs) < static_cast<double>(rhs);
}

inline bool operator>(const Fraction& lhs, const Fraction& rhs) { return operator<(rhs, lhs); }

inline bool operator<=(const Fraction& lhs, const Fraction& rhs) { return !operator>(lhs, rhs); }

inline bool operator>=(const Fraction& lhs, const Fraction& rhs) { return !operator<(lhs, rhs); }



} // namespace IntegralMath



#endif // FRACTION_HPP