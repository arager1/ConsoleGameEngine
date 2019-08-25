
SET(LIBNAME CatagoricalDistribution)

SET(SOURCES CatagoricalDistribution.hpp 
			CatagoricalDistribution.inl 
            Catagory.hpp)

ADD_LIBRARY(${LIBNAME} INTERFACE)

TARGET_INCLUDE_DIRECTORIES(${LIBNAME} INTERFACE 
						   ${PROJECT_SOURCE_DIR}/Source/IntegralMath/Fraction)

TARGET_LINK_LIBRARIES(${LIBNAME} INTERFACE Fraction)

ADD_SUBDIRECTORY(Test)
