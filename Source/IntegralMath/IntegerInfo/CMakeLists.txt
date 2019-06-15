


SET(LIBNAME IntegerInfo)
SET(SOURCES IntegerInfo.hpp IntegerInfo.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
