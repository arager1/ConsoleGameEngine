


SET(LIBNAME OverflowDetector)
SET(SOURCES OverflowDetector.hpp OverflowDetector.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${LIBNAME} PUBLIC 
						   ${PROJECT_SOURCE_DIR}/Source/IntegralMath/IntegerInfo)

ADD_SUBDIRECTORY(Test)
