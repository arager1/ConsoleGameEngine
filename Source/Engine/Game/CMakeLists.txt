
SET(LIBNAME AbstractGame)

SET(SOURCES AbstractGame.hpp 
			AbstractGame.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
