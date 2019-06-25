

#include "AbstractGame.hpp"
#include "PointerLogic.hpp"

#include <memory>

///// TEMP
#include <iostream>

namespace Engine
{

class ConsoleGame : public Engine::AbstractGame
{
public:
	void init()
	{
		std::cout << "ConsoleGame Init" << std::endl;
	}
	Status run()
	{
		std::cout << "ConsoleGame Run: " << m_count << std::endl;
		m_count++;
		if (m_count >= 10) return Status::Quit;
		else return Status::Ok;
	}
private:
	int m_count{0};
};


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

