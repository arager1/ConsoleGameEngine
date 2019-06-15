

#include "Fraction.hpp"
#include "gtest/gtest.h"

using namespace IntegralMath;

TEST(Reduction, NumIsFactor)
{
	Fraction f0{2, 4};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 2);

	Fraction f1{42, 2310};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 55);

	Fraction f2{821, 383407};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 467);

	Fraction f3{-2, 4};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), -1);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 2);

	Fraction f4{42, -2310};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), -1);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 55);

	Fraction f5{-821, -383407};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 467);
}

TEST(Reduction, DenIsFactor)
{
	Fraction f0{12, 4};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 3);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f1{1064, 56};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 19);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f2{54144, 128};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 423);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f3{-12, 4};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), -3);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f4{1064, -56};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), -19);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f5{-54144, -128};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 423);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 1);
}

TEST(Reduction, NumIsZero)
{
	Fraction f0{0, 1};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 0);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f1{0, 321};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 0);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f2{0, 7654566};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 0);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f3{0, -4};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), 0);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f4{0, -56};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), 0);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f5{0, -122348};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 0);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 1);
}

TEST(Reduction, NumIsOne)
{
	Fraction f0{1, 1};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f1{1, 534};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 534);

	Fraction f2{1, 7345624};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 7345624);

	Fraction f3{1, -6};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), -1);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 6);

	Fraction f4{1, -3234};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), -1);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 3234);

	Fraction f5{-1, -1456045};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 1);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 1456045);
}

TEST(Reduction, DenIsOne)
{
	Fraction f0{2, 1};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 2);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f1{678, 1};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 678);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f2{23904920, 1};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 23904920);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f3{-3, 1};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), -3);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f4{1598, -1};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), -1598);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 1);

	Fraction f5{-9485920, -1};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 9485920);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 1);
}

TEST(Reduction, CanReduce)
{
	Fraction f0{6, 4};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 3);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 2);

	Fraction f1{6, 12352};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 3);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 6176);

	Fraction f2{336, 598722};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 56);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 99787);

	Fraction f3{-1638, 420};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), -39);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 10);

	Fraction f4{24985, -10};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), -4997);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 2);

	Fraction f5{-4729052, -432};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 1182263);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 108);
}

TEST(Reduction, CoprimeFractionTerms)
{	
	Fraction f0{3, 8};
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Numerator), 3);
	EXPECT_EQ(f0.get(Fraction::FractionTerm::Denominator), 8);

	Fraction f1{89731, 18};
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Numerator), 89731);
	EXPECT_EQ(f1.get(Fraction::FractionTerm::Denominator), 18);

	Fraction f2{437, 4729052};
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Numerator), 437);
	EXPECT_EQ(f2.get(Fraction::FractionTerm::Denominator), 4729052);

	Fraction f3{-5, 24};
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Numerator), -5);
	EXPECT_EQ(f3.get(Fraction::FractionTerm::Denominator), 24);

	Fraction f4{4892, -433};
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Numerator), -4892);
	EXPECT_EQ(f4.get(Fraction::FractionTerm::Denominator), 433);

	Fraction f5{-4892, -9090275};
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Numerator), 4892);
	EXPECT_EQ(f5.get(Fraction::FractionTerm::Denominator), 9090275);


}
