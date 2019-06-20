#ifndef ENGINE_ABSTRACTGAME_HPP
#define ENGINE_ABSTRACTGAME_HPP


namespace Engine
{



class AbstractGame
{
public:
	enum class Status
	{
		Ok,
		Quit,
		Error
	};

	AbstractGame() = default;
	AbstractGame(const AbstractGame&) = default;
	AbstractGame(AbstractGame&&) = default;
	AbstractGame& operator=(const AbstractGame&) = default;
	AbstractGame& operator=(AbstractGame&&) = default;
	virtual ~AbstractGame() = default;

	virtual void init() = 0;
	virtual Status run() = 0;

private:

};



} // namespace Game

#endif // ENGINE_ABSTRACTGAME_HPP