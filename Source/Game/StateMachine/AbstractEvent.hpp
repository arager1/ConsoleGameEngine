#ifndef GAME_ABSTRACTEVENT_HPP
#define GAME_ABSTRACTEVENT_HPP

// #include <memory>


namespace Game
{

class AbstractEvent
{
public:
	AbstractEvent() = default;
	AbstractEvent(const AbstractEvent&) = default;
	AbstractEvent(AbstractEvent&&) = default;
	AbstractEvent& operator=(const AbstractEvent&) = default;
	AbstractEvent& operator=(AbstractEvent&&) = default;
	~AbstractEvent() = default;
	
private:

};



} // namespace Game


#endif // GAME_ABSTRACTEVENT_HPP
