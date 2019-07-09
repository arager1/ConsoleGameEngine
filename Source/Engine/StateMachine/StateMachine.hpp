#ifndef GAME_STATEMACHINE_HPP
#define GAME_STATEMACHINE_HPP

#include "AbstractState.hpp"
#include "AbstractEvent.hpp"
#include "InitState.hpp"

namespace Engine
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

	StateMachine(const StateMachine& other) = default;
	StateMachine(StateMachine&& other) = default;
	StateMachine& operator=(const StateMachine&) = default;
	StateMachine& operator=(StateMachine&&) = default;
	~StateMachine() = default;

	inline Status signal(std::unique_ptr<AbstractEvent> event)
	{
		auto temp = std::move(m_currentState);

		// m_currentState is invalid between these calls

		m_currentState = std::move(m_currentState->recieve(std::move(event)));

		return ((temp == m_currentState) ? Status::Idle : Status::Transition);
	}

	inline std::shared_ptr<const AbstractState> getCurrentState()
	{
		return m_currentState;
	}

private:
	std::shared_ptr<AbstractState> m_currentState;
};


} // namespace Game


#endif // GAME_STATEMACHINE_HPP

