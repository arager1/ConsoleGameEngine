

#include "GameLoop.hpp"

#ifndef ENGINE_ONLY_MODE
// include a real game file somehow
#else
#include "TestGame.hpp"
#endif


int main()
{
	// Setup code here

	{	// Game is constructed
		#ifndef ENGINE_ONLY_MODE
		Engine::RealGame game {std::move(std::make_unique<Engine::RealGameWorld>())};
		#else
		Engine::TestGame game {std::move(std::make_unique<Engine::TestGameWorld>())};
		#endif

        Engine::GameLoop<10> gameLoop;

        try
        {
            gameLoop.begin(game);
        }
        catch(const std::exception& exception)
        {
            
        }
	}	// Game is destroyed

	// Cleanup code here

	return 0;
}

