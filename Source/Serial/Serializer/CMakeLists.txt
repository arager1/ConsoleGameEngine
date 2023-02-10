
SET(LIBNAME ObjectFactory)

SET(SOURCES ObjectFactory.hpp 
			ObjectFactory.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
