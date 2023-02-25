
SET(LIBNAME IGame)

SET(SOURCES 
    Game.cpp
    GameLoop.hpp
    IGame.hpp
    GameEntity.hpp
    GameLogger.hpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)

ADD_SUBDIRECTORY(Main)
