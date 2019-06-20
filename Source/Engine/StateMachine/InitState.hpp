#ifndef GAME_INITSTATE_HPP
#define GAME_INITSTATE_HPP

#include "AbstractState.hpp"

namespace Engine
{

class AbstractEvent;

class InitState : public AbstractState
{
public:
	InitState() = default;
	InitState(const InitState&) = default;
	InitState(InitState&&) = default;
	InitState& operator=(const InitState&) = default;
	InitState& operator=(InitState&&) = default;
	~InitState() = default;

	virtual std::shared_ptr<AbstractState> recieve(std::unique_ptr<AbstractEvent> event) = 0;

private:

};


} // namespace Game


#endif // GAME_INITSTATE_HPP