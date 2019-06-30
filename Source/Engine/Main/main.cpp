

#include "ConsoleGame.hpp"
#include "PointerLogic.hpp"

#include <memory>

namespace Engine
{


}

int main()
{	
	{	// Game is constructed
		auto game = std::move(Engine::makeConsoleGame());

		game->init();

		auto status = Engine::AbstractGame::Status::Ok;
		do
		{
			status = game->run();
		}
		while (Engine::AbstractGame::Status::Quit != status);
	}	// Game is destroyed

	return 0;
}

