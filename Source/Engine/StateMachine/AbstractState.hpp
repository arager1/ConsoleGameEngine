#ifndef GAME_ABSTRACTSTATE_HPP
#define GAME_ABSTRACTSTATE_HPP

#include <memory>

namespace Engine
{

class AbstractEvent;

class AbstractState
{
public:
	AbstractState() = default;
	AbstractState(const AbstractState&) = default;
	AbstractState(AbstractState&&) = default;
	AbstractState& operator=(const AbstractState&) = default;
	AbstractState& operator=(AbstractState&&) = default;
	~AbstractState() = default;

	virtual std::shared_ptr<AbstractState> recieve(std::unique_ptr<AbstractEvent> event) = 0;

private:

};


} // namespace Game


#endif // GAME_ABSTRACTSTATE_HPP