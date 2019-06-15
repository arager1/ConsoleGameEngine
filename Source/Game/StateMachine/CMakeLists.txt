

SET(LIBNAME StateMachine)

SET(SOURCES StateMachine.hpp 
			StateMachine.cpp 
			AbstractState.hpp 
			AbstractState.cpp 
			InitState.hpp 
			InitState.cpp 
			AbstractEvent.hpp 
			AbstractEvent.cpp)

ADD_LIBRARY(${LIBNAME} ${SOURCES})

ADD_SUBDIRECTORY(Test)
