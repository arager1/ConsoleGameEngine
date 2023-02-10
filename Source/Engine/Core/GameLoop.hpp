#ifndef ENGINE_GAMELOOP_HPP
#define ENGINE_GAMELOOP_HPP

#include <chrono>
#include <thread>

#include "IGame.hpp"
#include "GameEntity.hpp"


namespace Engine
{

template <int TimeStepPeriod>
class GameLoop
{
public:
    void begin(IGame& game)
    {
        game.init();

        GameLoop::recordTimestamp();

        while (!game.quitGame())
        {
            GameLoop::updateGameLag();

            game.processGameInput();

            while (gameModelIsBehind())
            {
                game.updateGameModel();
                GameLoop::incrementGameTime();
            }

            game.renderGameOutput();

            game.cleanup();

            if (m_currentGameLag < getTimeStepPeriod()) std::this_thread::sleep_for(getTimeStepPeriod() - m_currentGameLag);
        }

        game.tearDown();
    }

private:
    std::chrono::time_point<std::chrono::system_clock> m_lastRecordedTimestamp;

    std::chrono::duration<double, std::milli> m_currentGameLag;

    inline void recordTimestamp(decltype(m_lastRecordedTimestamp) newTimeStamp = std::chrono::system_clock::now())
    {
        m_lastRecordedTimestamp = newTimeStamp;
    }

    inline void updateGameLag()
    {
        const decltype(m_lastRecordedTimestamp) newTimestamp {std::chrono::system_clock::now()};
        m_currentGameLag += (newTimestamp - m_lastRecordedTimestamp);
        recordTimestamp(newTimestamp);
    }

    inline bool gameModelIsBehind() const { return m_currentGameLag >= getTimeStepPeriod(); }

    inline void incrementGameTime() { m_currentGameLag -= getTimeStepPeriod(); }

    inline auto getTimeStepPeriod() const { return decltype(m_currentGameLag){TimeStepPeriod * 1.0}; }

    inline auto getNormalizedLag() const { return (m_currentGameLag / getTimeStepPeriod()); }
};


} // namespace Engine


#endif // ENGINE_GAMELOOP_HPP
