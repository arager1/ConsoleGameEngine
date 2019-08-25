

#ifndef ENGINE_ONLY_MODE
#include "ConsoleGame.hpp"
#else
// Use EmptyConsoleGame
#include <iostream>
#include "CatagoricalDistribution.hpp"
#endif

#include "PointerLogic.hpp"
#include "AbstractGame.hpp"

#include <memory>

namespace Engine
{

#ifndef ENGINE_ONLY_MODE
// Use user-defined console game
#else
enum class Catagories
{
	Mercury,
	Venus,
	Earth,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune
};
std::ostream& operator<<(std::ostream& os, const Catagories& catagory)
{
	switch (catagory)
	{
		case Catagories::Mercury: 	os << "Mercury"; 	break;
		case Catagories::Venus: 	os << "Venus"; 		break;
		case Catagories::Earth: 	os << "Earth"; 		break;
		case Catagories::Mars: 		os << "Mars"; 		break;
		case Catagories::Jupiter: 	os << "Jupiter"; 	break;
		case Catagories::Saturn: 	os << "Saturn"; 	break;
		case Catagories::Uranus: 	os << "Uranus"; 	break;
		case Catagories::Neptune: 	os << "Neptune"; 	break;
		default: 										break;
	}
	return os;
}
class TestConsoleGame : public AbstractGame
{
public:

	void init() override
	{
		// std::cout << "Init\n";
		m_dist.update(Catagories::Venus, 1);
		m_dist.update(Catagories::Earth, 2);
		m_dist.update(Catagories::Mars, 4);
		m_dist.update(Catagories::Jupiter, 8);
		m_dist.update(Catagories::Saturn, 16);
		m_dist.update(Catagories::Uranus, 32);
		m_dist.update(Catagories::Neptune, 64);
	}

	AbstractGame::Status run() override
	{
		// std::cout << "Run: " << m_runCount << "\n";
		if (m_runCount++ <= 10)
		{
			std::cout << m_dist.generate() << "\n";
			return AbstractGame::Status::Ok;
		}
		else return AbstractGame::Status::Quit;
	}

	

private:
	int m_runCount {0};
	RandomDistribution::CatagoricalDistribution<Catagories> m_dist {Catagories::Mercury};
};

#endif

}




int main()
{	
	// Setup code here

	{	// Game is constructed
		#ifndef ENGINE_ONLY_MODE
		auto game = std::move(std::make_unique<Engine::ConsoleGame>());
		#else
		auto game = std::move(std::make_unique<Engine::TestConsoleGame>());
		#endif

		game->init();

		for (auto status = game->run();
			 Engine::AbstractGame::Status::Quit != status;
			 ;)
		{
			
		}
	}	// Game is destroyed

	// Cleanup code here

	return 0;
}

