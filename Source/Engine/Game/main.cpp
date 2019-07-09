

#include "AbstractGame.hpp"
#include "PointerLogic.hpp"

#include <memory>

namespace Engine
{


}

int main()
{	
	{	// Game is constructed
		std::unique_ptr<Engine::AbstractGame> game = std::move(
			IntegralMath::PointerLogic::makeUnique<Engine::ConsoleGame>());

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

