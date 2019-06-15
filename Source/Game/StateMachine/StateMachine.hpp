#ifndef GAME_STATEMACHINE_HPP
#define GAME_STATEMACHINE_HPP

#include "AbstractState.hpp"
#include "AbstractEvent.hpp"
#include "InitState.hpp"

namespace Game
{


class StateMachine
{
public:

	enum class Status
	{
		Idle,
		Transition
	};

	StateMachine() = delete;

	StateMachine(std::shared_ptr<InitState> initState) :
		m_currentState{std::move(initState)}
	{

	}

	StateMachine(const StateMachine& other) = delete;
	StateMachine(StateMachine&& other) = delete;
	StateMachine& operator=(const StateMachine&) = delete;
	StateMachine& operator=(StateMachine&&) = delete;
	~StateMachine() = default;

	inline Status signal(std::unique_ptr<AbstractEvent> event)
	{
		auto temp = std::move(m_currentState);

		m_currentState = std::move(m_currentState->recieve(std::move(event)));

		return ((temp == m_currentState) ? Status::Idle : Status::Transition);
	}

	inline std::shared_ptr<AbstractState> getCurrentState()
	{
		return std::move(m_currentState);
	}

private:
	std::shared_ptr<AbstractState> m_currentState;
};


} // namespace Game


#endif // GAME_STATEMACHINE_HPP

