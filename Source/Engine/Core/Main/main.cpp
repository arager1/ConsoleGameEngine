

#include "GameLoop.hpp"

#ifndef ENGINE_ONLY_MODE
// include a real game file somehow
#else
#include "EngineOnlyMode/DummyGame.hpp"
#endif


int main()
{
	// Setup code here
    Engine::Logging::clearLogFile();

	{	// Game is constructed
		#ifndef ENGINE_ONLY_MODE
		Engine::RealGame game {std::move(std::make_unique<Engine::RealGameWorld>())};
		#else
		Engine::DummyGame game {std::move(std::make_unique<Engine::DummyGameWorld>())};
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

