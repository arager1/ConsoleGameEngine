#ifndef GAME_Context_HPP
#define GAME_Context_HPP

#include <memory>

namespace Engine
{

class IEvent
{
public:
	
private:

};

class Context;

class IState
{
public:
	virtual void recieve(const IEvent& event, Context& context) = 0;

private:

};

class Context
{
public:
    template <typename InitialStateType>
    inline void init() { m_state = std::move(std::make_unique<InitialStateType>()); }

    inline bool isInitialized() const { return (m_state != nullptr); }

	void signal(const IEvent& event)
	{
        // Forward the incoming event to the current state and give current state a mechanism to transition
        if (isInitialized()) m_state->recieve(event, *this);
	}

	inline const IState& state() const { return *m_state; }

    template <typename NewStateType>
    inline void transitionTo(std::unique_ptr<IState> newState) {m_state = std::move(newState);}
    
private:
	std::unique_ptr<IState> m_state {nullptr};
};


} // namespace Engine


#endif // GAME_Context_HPP

