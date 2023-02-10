


#include "Rational.hpp"

#include <stdexcept>

using Mathematic::Types::Rational;

constexpr Rational::Rational(const int numerator, const int denominator) :
    m_numerator{numerator}, m_denominator{denominator} 
{
    verify();
    reduce();
}

constexpr Rational& Rational::operator+=(const Rational& rhs)
{
	m_numerator = (m_numerator * rhs.m_denominator) + (rhs.m_numerator * m_denominator);
	m_denominator *= rhs.m_denominator;
	reduce();
	return *this;
}

constexpr Rational& Rational::operator-=(const Rational& rhs)
{
	m_numerator = (m_numerator * rhs.m_denominator) - (rhs.m_numerator * m_denominator);
	m_denominator *= rhs.m_denominator;
	reduce();
	return *this;
}

constexpr Rational& Rational::operator*=(const Rational& rhs)
{
	m_numerator *= rhs.m_numerator;
	m_denominator *= rhs.m_denominator;
	reduce();
	return *this;
}

constexpr Rational& Rational::operator/=(const Rational& rhs)
{
	m_numerator *= rhs.m_denominator;
	m_denominator *= rhs.m_numerator;
	verify();
	reduce();
	return *this;
}

constexpr void Rational::reduce()
{
    if (Information::isZero(m_numerator))
    {
        m_denominator = Constants::one;
    }
    else if (Information::isOne(Operations::absVal(m_numerator)) ||
             Information::isOne(Operations::absVal(m_denominator)))
    {
        
    }
    else
    {
    	const int gcf = Information::greatestCommonFactor(m_numerator, m_denominator);
		m_numerator /= gcf;
		m_denominator /= gcf;
    }
    
    if (Information::isNeg(m_denominator))
    {
        m_numerator = Operations::invert(m_numerator);
        m_denominator = Operations::invert(m_denominator);
    }
}


void Rational::verify()
{
    if (Information::isZero(m_denominator)) throw std::range_error("Mathematic::Types::Rational denominator became 0");
}

