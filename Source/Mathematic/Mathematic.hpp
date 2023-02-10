#ifndef MATHEMATIC_MATHEMATIC
#define MATHEMATIC_MATHEMATIC

///@file Mathematic.hpp


#include <limits>

///@namespace Mathematic
/// Common Mathematic Expressions
namespace Mathematic
{

///@namespace Constants
/// Pre-defined Numeric Constants
namespace Constants
{



///@name Rational Constants
/// Provides constexpr values for common rational constants.
/// A rational number is any number that can be expressed as a quotient or fraction.
/// Integers are a subset of rational numbers.
///@{
    /// Zero (0)
	constexpr int zero {0};

    /// One (1)
	constexpr int one {1};

    /// Negative One (-1)
    constexpr int negOne {-1};

    /// The maximum c++ Numeric value
    template<typename Numeric>
    inline constexpr Numeric max() {return std::numeric_limits<Numeric>::max();}

    /// The minimum c++ Numeric value
    template<typename Numeric>
    inline constexpr Numeric min() {return std::numeric_limits<Numeric>::min();}

    // #include common fractions?
///@}


///@name Algebraic Irrational Constants
/// Provides constexpr values for common algebraic, irrational constants.
/// An algebraic number is any number that is a root of a (non-zero) polynomial.
/// Rationals are a subset of Algebraics but what follows are some common 
/// irrationals, precalculated to maintain constexpr.
///@{
    /// Pythagoras' Constant: SquareRoot(2)
	constexpr double pythagoras {1.41421356237309504880168872420969808};

    /// Pythagoras' Constant: SquareRoot(2)
	constexpr double sqrt2 {pythagoras};

    /// Theodorus' Constant: SquareRoot(3)
	constexpr double theodorus {1.73205080756887729352744634150587237};

    /// Theodorus' Constant: SquareRoot(3)
	constexpr double sqrt3 {theodorus};

    /// xxx Constant: SquareRoot(5)
	constexpr double xxx {2.23606797749978969640917366873127624};

    /// xxx Constant: SquareRoot(5)
	constexpr double sqrt5 {xxx};

    /// The Golden Ratio: phi
	constexpr double golden {1.61803398874989484820458683436563812};

    /// The Golden Ratio: phi
	constexpr double phi {golden};

    /// Delian's Constant: phi
	constexpr double delian {1.25992104989487316476721060727822835};

    /// Delian's Constant: phi
	constexpr double cbrt2 {delian};
///@}


///@name Transcendental Irrational Constants
/// Provides constexpr values for common transcendental constants. A transcendental 
/// number is any non-algebraic number. All transcendental numbers are irrational.
///@{
    /// Archimedes' Constant: pi
	constexpr double archimedes {3.14159265358979323846264338327950288};

    /// Archimedes' Constant: pi
	constexpr double pi {archimedes};

    /// Twice the value of pi: Tau
	constexpr double twopi {2.0 * pi};

    /// Twice the value of pi: Tau
	constexpr double tau {twopi};

    /// Euler's Constant: e
	constexpr double euler {2.71828182845904523536028747135266250};

    /// Euler's Constant: e
	constexpr double e {euler};

    /// The Natural Logarithm of 2: ln2
	constexpr double yyy {6.93147180559945309417232121458176568};

    /// The Natural Logarithm of 2: ln2
	constexpr double ln2 {yyy};
///@}

} // namespace Constants



///@namespace Information
/// Functions to retrieve common Numeric Information 
namespace Information
{

///@name Templated Numeric Information
/// Provides constexpr predicates for common Numeric operations (integer, double, Rational, etc.). 
///@{
    /// Is this Numeric equal to zero
	///@param n a Numeric
	///@returns True when n is equal to 0. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
	template<typename Numeric>
	inline constexpr bool isZero(const Numeric n) {return n == Numeric{Constants::zero};}

    template<>
    inline constexpr bool isZero(const int n) {return n == Constants::zero;}

    /// Is this Numeric equal to one
	///@param n a Numeric
	///@returns True when n is equal to 1. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
	template<typename Numeric>
	inline constexpr bool isOne(const Numeric n) {return n == Numeric{Constants::one};}

    template<>
	inline constexpr bool isOne(const int n) {return n == Constants::one;}

    /// Is this Numeric equal to negative one
	///@param n a Numeric
	///@returns True when n is equal to -1. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
    template<typename Numeric>
	inline constexpr bool isNegOne(const Numeric n) {return n == Numeric{Constants::negOne};}

    template<>
	inline constexpr bool isNegOne(const int n) {return n == Constants::negOne;}

    /// Is this Numeric equal to the maximum value possible value
	///@param n a Numeric
	///@returns True when n is equal to std::numeric_limits<Numeric>::max(). False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
    ///@requires std::numeric_limits<Numeric>
    template<typename Numeric>
	inline constexpr bool isMax(const Numeric n) {return n == Constants::max<Numeric>();}

    template<>
	inline constexpr bool isMax(const int n) {return n == Constants::max<int>();}

    /// Is this Numeric equal to the minimum value possible value
	///@param n a Numeric
	///@returns True when n is equal to std::numeric_limits<Numeric>::min(). False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
    ///@requires std::numeric_limits<Numeric>
	template<typename Numeric>
	inline constexpr bool isMin(const Numeric n) {return n == Constants::min<Numeric>();}

    template<>
	inline constexpr bool isMin(const int n) {return n == Constants::min<int>();;}

    /// Is this Numeric positive
	///@param n a Numeric
	///@returns True when n is greater than 0. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
	template<typename Numeric>
	inline constexpr bool isPos(const Numeric n) {return n > Numeric{Constants::zero};}

	template<>
	inline constexpr bool isPos(const int n) {return n > Constants::zero;}

    /// Is this Numeric negative
	///@param n a Numeric
	///@returns True when n is less than 0. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
	template<typename Numeric>
	inline constexpr bool isNeg(const Numeric n) {return n < Numeric{Constants::zero};}

	template<>
	inline constexpr bool isNeg(const int n) {return n < Constants::zero;}

    /// Is this Nuneric non-zero
	///@param n a Numeric
	///@returns True when n is not equal to 0. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
    template<typename Numeric>
	inline constexpr bool isNonZero(const Numeric n) {return n != Numeric{Constants::zero};}

    template<>
	inline constexpr bool isNonZero(const int n) {return n != Constants::zero;}


    /// Are these Numerics equal
	///@param n a Numeric
    ///@param m a Numeric
	///@returns True when n is equal to m. False otherwise.
    ///@requires Numeric::Numeric(int)
    ///@requires bool Numeric::operator==(const Numeric&)
    template<typename Numeric>
	inline constexpr bool areEqual(const Numeric n, const Numeric m) {return n == m;}

    template<>
	inline constexpr bool areEqual(const int n, const int m) {return n == m;}
///@}



///@name Integer-Specific Information
/// Provides constexpr functions for common integer operations
///@{
    /// Is n a factor of m.
    /// Order of parameters is SIGNIFICANT
	///@param n an integer factor to test against a product
    ///@param m an integer product to test against a factor
	///@returns True when m modulo n is equal to 0. False otherwise.
    inline constexpr bool isFactor(const int n, const int m) {return isZero(m % n);}

    /// What is the greatest common factor between n and m.
    /// Order of parameters is NOT significant.
	///@param n an integer
    ///@param m an integer
	///@returns The greatest integer value that is a factor of both n and m
    constexpr int greatestCommonFactor(const int n, const int m);

    /// What is (n!).
	///@param n an integer
	///@returns The the factorial of n
    constexpr int factorial(const int n);
///@}

///@name Floating Point, Geometric Information
/// Provides constexpr functions for common geometric operations
///@{
    /// What is the area of an ellipse with semi-major axis length a and semi-minor axis length b.
    /// Order of parameters is NOT significant.
    ///@param a the length of the longest semi-axis of the ellipse
    ///@param b the length of the shortest semi-axis of the ellipse
    ///@returns The floating-point area of the ellipse defined by a and b
	inline constexpr double ellipseArea(const double a, const double b) {return Constants::pi * a * b;}
    
    /// What is the area of a circle with radius-length r.
    ///@param r the radius-length of the circle
    ///@returns The floating-point area of the circle defined by r
    inline constexpr double circleArea(const double r) {return ellipseArea(r, r);}
    
    // /* Nontrivial */ double ellipseCircumference(const double a, const double b);

    /// What is the circumference of a circle with radius-length r.
    ///@param r the radius-length of the circle
    ///@returns The floating-point circumference of the circle defined by r
    inline constexpr double circleCircumference(const double r) {return Constants::tau * r;}

    /// What is the volume of an ellipsoid with principle semi-axes a, b, and c.
    /// Order of parameters is NOT significant.
    ///@param a the length of the longest semi-axis of the ellipsoid
    ///@param b the length of the median semi-axis of the ellipsoid
    ///@param c the length of the shortest semi-axis of the ellipsoid
    ///@returns The floating-point volume of the ellipsoid defined by a, b, and c
	inline constexpr double ellipsoidVolume(const double a, const double b, const double c) {return Constants::pi * (4.0/3.0) * a * b * c;}

    /// What is the volume of a sphere with radius-length r
    ///@param r the radius-length of the sphere
    ///@returns The floating-point volume of the sphere defined by r
	inline constexpr double sphereVolume(const double r) {return ellipsoidVolume(r, r, r);}

    // /* Nontrivial */ double ellipsoidSurfaceArea(const double a, const double b, const double c);

    /// What is the surface-area of a sphere with radius-length r
    ///@param r the radius-length of the sphere
    ///@returns The floating-point surface-area of the sphere defined by r
	inline constexpr double sphereSurfaceArea(const double r) {return Constants::pi * 4.0 * r * r;}
///@}


///@name Type Limitation Detection
/// Provides constexpr predicates for sanity checks on c++ operations 
///@{
    /// Will the sum of lhs and rhs overflow the c++ int type.
    /// Order of parameters is NOT significant.
    ///@param lhs a term in the addition
    ///@param rhs a term in the addition
    ///@returns True when (lhs + rhs) would overflow int. False otherwise.
    inline constexpr bool additionWillOverflow(const int lhs, const int rhs);

    /// Will the difference of lhs and rhs overflow the c++ int type.
    /// Order of parameters is SIGNIFICANT.
    ///@param lhs the minuend of the subraction
    ///@param rhs the subtruend of the subraction
    ///@returns True when (lhs - rhs) would overflow int. False otherwise.
    inline constexpr bool subtractionWillOverflow(const int lhs, const int rhs);

    /// Will the product of lhs and rhs overflow the c++ int type.
    /// Order of parameters is NOT significant.
    ///@param lhs a factor in the multtiplication
    ///@param rhs a factor in the multtiplication
    ///@returns True when (lhs * rhs) would overflow int. False otherwise.
    inline constexpr bool multiplicationWillOverflow(const int lhs, const int rhs);

    /// Will the quotient of lhs and rhs overflow the c++ int type.
    /// Order of parameters is SIGNIFICANT.
    ///@param lhs the dividend of the division
    ///@param rhs the divisor of the division
    ///@returns True when (lhs / rhs) would overflow int. False otherwise.
    inline constexpr bool divisionWillOverflow(const int lhs, const int rhs) {return (isMin(lhs) && isNegOne(rhs));}

    /// Will the modulo of lhs and rhs overflow the c++ int type.
    /// Order of parameters is SIGNIFICANT.
    ///@param lhs the dividend of the division
    ///@param rhs the divisor of the division
    ///@returns True when (lhs % rhs) would overflow int. False otherwise.
    inline constexpr bool moduloWillOverflow(const int lhs, const int rhs) {return divisionWillOverflow(lhs, rhs);}
///@}

} // namespace Information




namespace Operations
{
    /// Invert the sign of n
	///@param n a Numeric
	///@modifies If n is negative, make it positive. If n is positive, make it negative.
    ///@requires Numeric::Numeric(int)
    ///@requires Numeric& Numeric::operator*=(const Numeric&)
    template<typename Numeric>
	inline constexpr Numeric invert(const Numeric n) {return n * Numeric{Constants::negOne};}

    template<>
	inline constexpr int invert(const int n) {return n * Constants::negOne;}

    /// Absolute value of n
	///@param n a Numeric
	///@modifies Takes the absolute value of n
    ///@requires Numeric& std::abs<Numeric>(const Numeric& n)
    template<typename Numeric>
	inline constexpr int absVal(const Numeric n) {return (Information::isPos(n) || Information::isZero(n)) ? n : invert(n);}

} // namespace Operations



} // namespace Mathematic

#endif
