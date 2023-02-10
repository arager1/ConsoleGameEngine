#ifndef ENGINE_IGAME_HPP
#define ENGINE_IGAME_HPP


#include <memory>
#include <vector>
#include <queue>

#ifdef LOGGING_ENABLED
#include <string>
#include <sstream>
#include <fstream>
#endif

#include "GameEntity.hpp"

namespace Engine
{

class IGameInputInterface
{
public:
    // Produce a subset-interface to be passed to the Entity list at-large
    // This would exclude inputs which are only used at the Game World level
    virtual const EntityInputInterface& getEntityInputInterface() const = 0;


    // For child classes:

    // Define how Entities at-large interface with the Game World's inputs/game-controller
    // Player interface (controller, keypad, mouse, etc.)
    // AI-models (computer-players etc.)
    // Global RNG
    // Inter-game / game-console interface
};


class IGameRenderInterface
{
public:
    // Produce a subset-interface to be passed to the Entity list at-large
    // This would exclude rendering the Game World level
    virtual EntityRenderInterface& getEntityRenderInterface() = 0;


    // For child classes

    // Define how Entities at-large interface with the Game World's outputs/game-renderer
    // Game renderer - screen to be shown to player
    // Inter-game / game-console interface
};


class IGameWorld
{
public:
    virtual ~IGameWorld() = default;

    // Let the Game World read the game's inputs
    virtual void updateWorldInputs(const IGameInputInterface& gameInputInterface) = 0;

    // Update the Game World by one cycle
    virtual void updateWorldModel() = 0;

    // Let the Game World write to the game's renderer
    virtual void updateWorldRender(IGameRenderInterface& gameRenderInterface) = 0;


    inline void addEntity(std::unique_ptr<GameEntity> newEntity) { m_newEntityBuffer.push(std::move(newEntity)); }

    // Is there a better way?
    inline auto& getNewEntityBuffer() { return m_newEntityBuffer; }

private:
    std::queue<std::unique_ptr<GameEntity>> m_newEntityBuffer;
};


class IGame
{
public:
    IGame(std::unique_ptr<IGameWorld> gameWorld) : m_gameWorld{std::move(gameWorld)} {}

	virtual void init() = 0;

    virtual void tearDown() = 0;

    virtual bool quitGame() = 0;

    void processGameInput()
    {
        if (m_gameWorld) m_gameWorld->updateWorldInputs(getGameInputInterface());

        for (auto& entity : m_entities) entity->updateInputs(getGameInputInterface().getEntityInputInterface());
    }

    void updateGameModel()
    {
        if (m_gameWorld)
        {
            m_gameWorld->updateWorldModel();
            
            for (auto& entity : m_entities) entity->updateModel(*m_gameWorld);
        }
    }

    void renderGameOutput()
    {
        if (m_gameWorld) m_gameWorld->updateWorldRender(getGameRenderInterface());

        for (auto& entity : m_entities) entity->updateRenders(getGameRenderInterface().getEntityRenderInterface());
    }

    void cleanup()
    {
        removeDestroyedEntities();
        addNewEntities();

        #ifdef LOGGING_ENABLED
        writeMessageBuffer();
        #endif
    }

    void logMessage(const std::string& message)
    {
        #ifdef LOGGING_ENABLED
        for (std::string line; std::getline(m_messageBuffer, line);) m_messageBuffer << line << '\n';
        #endif
    }

private:
    std::unique_ptr<IGameWorld> m_gameWorld;

    std::vector<std::unique_ptr<GameEntity>> m_entities;

    #ifdef LOGGING_ENABLED
    std::stringstream m_messageBuffer;
    std::ofstream m_loggingFile;
    #endif

    virtual const IGameInputInterface& getGameInputInterface() const = 0;
    virtual IGameRenderInterface& getGameRenderInterface() = 0;

    void removeDestroyedEntities()
    {
        std::remove_if(m_entities.begin(), m_entities.end(), [](const std::unique_ptr<GameEntity>& entity){return entity->isDestroyed();});
    }

    void addNewEntities()
    {
        auto& newEntitiesBuffer {m_gameWorld->getNewEntityBuffer()};

        while (!newEntitiesBuffer.empty())
        {
            m_entities.push_back(std::move(newEntitiesBuffer.front()));
            newEntitiesBuffer.pop();
        }
    }

    void writeMessageBuffer()
    {
        #ifdef LOGGING_ENABLED
        m_loggingFile.open("HeadlessGame.log", std::ofstream::out | std::ofstream::app);
        for (std::string line; std::getline(m_messageBuffer, line);) m_loggingFile << line << '\n';
        m_loggingFile.close();
        m_messageBuffer.str(std::string{});
        #endif
    }
};


} // namespace Engine


#endif // ENGINE_IGAME_HPP


