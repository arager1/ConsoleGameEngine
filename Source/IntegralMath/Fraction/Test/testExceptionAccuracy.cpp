
#include "Fraction.hpp"
#include "gtest/gtest.h"

using namespace IntegralMath;

TEST(ExceptionAccuracy, OnExplicitConstruction)
{
	for (int n = -1000; n < 1000; ++n)
	{
		for (int d = -1000; d < 1000; ++d)
		{
			if (d == 0) EXPECT_THROW(Fraction(n, d), std::runtime_error);
			else EXPECT_NO_THROW(Fraction(n, d));
		}
	}
}

TEST(ExceptionAccuracy, OnIntegerConstruction)
{
	for (int n = -1000; n < 1000; ++n)
	{
		EXPECT_NO_THROW(Fraction{n});
	}
}

TEST(ExceptionAccuracy, OnDefaultConstruction)
{
	EXPECT_NO_THROW(Fraction());
}

TEST(ExceptionAccuracy, OnAddition)
{
	for (int n0 = 0; n0 < 16; ++n0)
	{
		for (int d0 = 1; d0 < 16; ++d0)
		{
			for (int n1 = 0; n1 < 16; ++n1)
			{
				for (int d1 = 1; d1 < 16; ++d1)
				{
					Fraction f0 {n0, d0};
					Fraction f1 {n1, d1};
					EXPECT_NO_THROW(f0 + f1);
				}
			}
		}
	}
}

TEST(ExceptionAccuracy, OnSubtraction)
{
	for (int n0 = 0; n0 < 16; ++n0)
	{
		for (int d0 = 1; d0 < 16; ++d0)
		{
			for (int n1 = 0; n1 < 16; ++n1)
			{
				for (int d1 = 1; d1 < 16; ++d1)
				{
					Fraction f0 {n0, d0};
					Fraction f1 {n1, d1};
					EXPECT_NO_THROW(f0 - f1);
				}
			}
		}
	}
}


TEST(ExceptionAccuracy, OnMultiplication)
{
	for (int n0 = 0; n0 < 16; ++n0)
	{
		for (int d0 = 1; d0 < 16; ++d0)
		{
			for (int n1 = 0; n1 < 16; ++n1)
			{
				for (int d1 = 1; d1 < 16; ++d1)
				{
					Fraction f0 {n0, d0};
					Fraction f1 {n1, d1};
					EXPECT_NO_THROW(f0 * f1);
				}
			}
		}
	}
}


TEST(ExceptionAccuracy, OnDivision)
{
	for (int n0 = 0; n0 < 16; ++n0)
	{
		for (int d0 = 1; d0 < 16; ++d0)
		{
			for (int n1 = 1; n1 < 16; ++n1)
			{
				for (int d1 = 1; d1 < 16; ++d1)
				{
					Fraction f0 {n0, d0};
					Fraction f1 {n1, d1};
					EXPECT_NO_THROW(f0 / f1);
				}
			}
		}
	}
}

