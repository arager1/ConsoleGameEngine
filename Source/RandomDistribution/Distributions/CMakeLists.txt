
SET(LIBNAME Distributions)
SET(SOURCES AbstractDist.hpp 
			DiscreteDist.hpp 
			DiscreteDist.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
