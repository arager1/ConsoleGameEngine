#ifndef ENGINE_TESTGAME_HPP
#define ENGINE_TESTGAME_HPP

#ifdef ENGINE_ONLY_MODE

#include <iostream>

#include "IGame.hpp"

namespace Engine
{

class MonsterModelComponent : public IEntityModelComponent
{
    void update(const IGameWorld& gameWorld) override
    {

    }

    bool isDestroyed() const override
    {
        return m_health <= 0;
    }
private:
    int m_health {10};
};

class MonsterInputComponent : public IEntityInputComponent
{
public:
    void update(const EntityInputInterface&, IEntityModelComponent&) const override
    {
        // if (m_idleCount >= 3) m_idling = false;



        // if (m_idling) ++m_idleCount;
        // else m_idleCount = 0;
    }
private:
    bool m_idling {true};
    int m_idleCount {0};
};

class MonsterRenderComponent : public IEntityRenderComponent
{
    void update(const IEntityModelComponent&, EntityRenderInterface&) const override
    {

    }
};


class TestEntityInputInterface : public EntityInputInterface
{
public:
    enum class Direction {Up, Right, Down, Left, None};

    Direction m_playerDirectionInput {Direction::None};
};

class TestInputInterface : public IGameInputInterface
{
    const EntityInputInterface& getEntityInputInterface() const final {return entityInputInterface;}

    int mouseCoordinateX;
    int mouseCoordinateY;

private:
    TestEntityInputInterface entityInputInterface;
};

class TestEntityRenderInterface : public EntityRenderInterface
{
public:
    bool m_entitiesVisible;
};

class TestRenderInterface : public IGameRenderInterface
{
    EntityRenderInterface& getEntityRenderInterface() final {return entityRenderInterface;}

    int outputScreenWidth;
    int outputScreenHeight;

private:
    TestEntityRenderInterface entityRenderInterface;
};


class TestGameWorld : public IGameWorld
{
public: 
    void updateWorldInputs(const IGameInputInterface& gameInputInterface) override
    {
        std::cout << "Game World reading Game Inputs" << std::endl;
    }

    void updateWorldModel() override
    {
        std::cout << "Game World updating" << std::endl;

        if (cycleTimer == 2)
        {
            IGameWorld::addEntity(std::move(std::make_unique<GameEntity>
            (
                std::move(std::make_unique<MonsterInputComponent>()),
                std::move(std::make_unique<MonsterModelComponent>()),
                std::move(std::make_unique<MonsterRenderComponent>())
            )));
        }

        ++cycleTimer;
    }

    void updateWorldRender(IGameRenderInterface& gameRenderInterface) override
    {
        std::cout << "Game World writing to Game Renderer" << std::endl;
    }

private:
    int cycleTimer {0};
};


class TestGame : public IGame
{
public:
    TestGame(std::unique_ptr<IGameWorld> gameWorld) : IGame(std::move(gameWorld)) {}
    
	void init() final
    {
        logMessage("Initializing game");
    }

    void tearDown() final
    {
        logMessage("Tearing down game");
    }

    bool quitGame() final
    {
        if (cycleCount++ >= 10)
        {
            logMessage("Quit condition reached");
            return true;
        }
        else return false;
    }

    const IGameInputInterface& getGameInputInterface() const final {return m_testInputInterface;}

    IGameRenderInterface& getGameRenderInterface() final {return m_testRenderInterface;}

private:
    int cycleCount {0};

    TestInputInterface m_testInputInterface;
    TestRenderInterface m_testRenderInterface;
};



} // namespace Engine

#endif // ENGINE_ONLY_MODE

#endif // ENGINE_TESTGAME_HPP