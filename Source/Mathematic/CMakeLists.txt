
SET(LIBNAME Mathematic)

SET(SOURCES Mathematic.hpp
            Mathematic.cpp
            Rational.hpp
            Rational.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
