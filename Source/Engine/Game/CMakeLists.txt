
SET(EXENAME AbstractGame)

SET(SOURCES AbstractGame.hpp 
			AbstractGame.cpp 
			main.cpp)

ADD_EXECUTABLE(${EXENAME} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${EXENAME} PUBLIC 
						   ${CMAKE_SOURCE_DIR}/Source/IntegralMath/PointerLogic)

TARGET_LINK_LIBRARIES(${EXENAME} PointerLogic)

ADD_SUBDIRECTORY(Test)
