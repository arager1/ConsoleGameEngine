
ADD_EXECUTABLE(TestCatagoricalDistribution TestCatagoricalDistribution.cpp)

TARGET_INCLUDE_DIRECTORIES(TestCatagoricalDistribution PUBLIC 
						   ${PROJECT_SOURCE_DIR}/Source/RandomDistribution/CatagoricalDistribution)

TARGET_LINK_LIBRARIES(TestCatagoricalDistribution 
					  CatagoricalDistribution
					  gtest_main)

ADD_TEST(NAME CatagoricalDistribution COMMAND TestCatagoricalDistribution)