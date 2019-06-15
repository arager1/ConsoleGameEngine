

#include "Fraction.hpp"
#include "IntegralFunctions.hpp"

#include <exception>





namespace IntegralMath
{



Fraction::Fraction(int numerator, int denominator) :
	m_numerator(numerator),
	m_denominator(denominator)
{
	verify("construction");
	reduce();
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
	m_numerator = (m_numerator * rhs.m_denominator) + (rhs.m_numerator * m_denominator);
	m_denominator *= rhs.m_denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs)
{
	m_numerator = (m_numerator * rhs.m_denominator) - (rhs.m_numerator * m_denominator);
	m_denominator *= rhs.m_denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& rhs)
{
	m_numerator *= rhs.m_numerator;
	m_denominator *= rhs.m_denominator;
	reduce();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
	m_numerator *= rhs.m_denominator;
	m_denominator *= rhs.m_numerator;
	verify("division");
	reduce();
	return *this;
}

void Fraction::reduce()
{
	// If this Fraction evaluates to 0.0, set the denominator to 1
	if (IntegerInfo::isZero(m_numerator))
	{
		m_denominator = IntegerInfo::ONE;
	}

	// If the absolute value of either the numerator or denominator is 1, there is no work to do
	else if ( IntegerInfo::isOne(m_numerator) || IntegerInfo::isNegOne(m_numerator) ||
			  IntegerInfo::isOne(m_denominator) || IntegerInfo::isNegOne(m_denominator) )
	{

	}

	// Otherwise divide numerator and denominator by their greatest common factor
	else
	{
		const int gcf = IntegralFunctions::greatestCommonFactor(m_numerator, m_denominator);
		m_numerator /= gcf;
		m_denominator /= gcf;
	}

	// Normalize signs of numerator and denominator
	if (IntegerInfo::isNegative(m_denominator))
	{
		IntegralFunctions::invert(m_numerator);
		IntegralFunctions::invert(m_denominator);
	}
}


}

