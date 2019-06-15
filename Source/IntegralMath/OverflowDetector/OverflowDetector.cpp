
#include "OverflowDetector.hpp"
#include "IntegerInfo.hpp"


namespace IntegralMath
{



bool OverflowDetector::additionWillOverflow(int lhs, int rhs)
{
	return ( IntegerInfo::isPositive(rhs) && ( lhs > (IntegerInfo::INTMAX - rhs) ) ) || 
		   ( IntegerInfo::isNegative(rhs) && ( lhs < (IntegerInfo::INTMIN - rhs) ) ) ;
}


bool OverflowDetector::subtractionWillOverflow(int lhs, int rhs)
{
	return ( IntegerInfo::isNegative(rhs) && ( lhs > (IntegerInfo::INTMAX + rhs) ) ) || 
		   ( IntegerInfo::isPositive(rhs) && ( lhs < (IntegerInfo::INTMIN + rhs) ) ) ; 
}


bool OverflowDetector::multiplicationWillOverflow(int lhs, int rhs)
{
	return ( lhs > (IntegerInfo::INTMAX / rhs) ) || 
		   ( lhs < (IntegerInfo::INTMIN / rhs) ) || 
		   ( IntegerInfo::isNegOne(lhs) && IntegerInfo::isMin(rhs) ) || 
		   ( IntegerInfo::isNegOne(rhs) && IntegerInfo::isMin(lhs) ) ;
}



}