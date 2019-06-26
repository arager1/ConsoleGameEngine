

ADD_EXECUTABLE(TestFractionExceptionAccuracy testExceptionAccuracy.cpp)

TARGET_INCLUDE_DIRECTORIES(TestFractionExceptionAccuracy PUBLIC 
						   ${PROJECT_SOURCE_DIR}/Source/IntegralMath/Fraction)

TARGET_LINK_LIBRARIES(TestFractionExceptionAccuracy 
					  Fraction
					  gtest_main)

ADD_TEST(NAME FractionExceptionAccuracy COMMAND TestFractionExceptionAccuracy)






ADD_EXECUTABLE(TestFractionReduction testReduction.cpp)

TARGET_INCLUDE_DIRECTORIES(TestFractionReduction PUBLIC 
						   ${PROJECT_SOURCE_DIR}/Source/IntegralMath/Fraction)

TARGET_LINK_LIBRARIES(TestFractionReduction 
					  Fraction
					  gtest_main)

ADD_TEST(NAME FractionReduction COMMAND TestFractionReduction)










