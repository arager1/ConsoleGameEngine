


SET(LIBNAME PointerLogic)
SET(SOURCES PointerLogic.hpp PointerLogic.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
