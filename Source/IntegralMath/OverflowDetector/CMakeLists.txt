


SET(LIBNAME OverflowDetector)
SET(SOURCES OverflowDetector.hpp OverflowDetector.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${LIBNAME} PUBLIC 
						   ${CMAKE_SOURCE_DIR}/IntegralMath/IntegerInfo)

ADD_SUBDIRECTORY(Test)
