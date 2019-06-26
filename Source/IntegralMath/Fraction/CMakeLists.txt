

SET(LIBNAME Fraction)
SET(SOURCES Fraction.hpp Fraction.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${LIBNAME} PUBLIC 
						   ${PROJECT_SOURCE_DIR}/Source/IntegralMath/IntegerInfo 
						   ${PROJECT_SOURCE_DIR}/Source/IntegralMath/IntegralFunctions)

TARGET_LINK_LIBRARIES(${LIBNAME} IntegerInfo IntegralFunctions)

ADD_SUBDIRECTORY(Test)
