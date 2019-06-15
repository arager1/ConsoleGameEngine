


SET(LIBNAME IntegralFunctions)
SET(SOURCES IntegralFunctions.hpp IntegralFunctions.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${LIBNAME} PUBLIC 
						   ${CMAKE_SOURCE_DIR}/IntegralMath/IntegerInfo)

TARGET_LINK_LIBRARIES(${LIBNAME} IntegerInfo)

ADD_SUBDIRECTORY(Test)
