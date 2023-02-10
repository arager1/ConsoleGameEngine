
SET(LIBNAME IGame)

SET(SOURCES GameLoop.hpp
            GameLoop.cpp
            IGame.hpp
            IGame.cpp
            GameEntity.hpp
            GameEntity.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
