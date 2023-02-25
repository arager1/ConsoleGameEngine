#ifndef ENGINE_DUMMYGAME_HPP
#define ENGINE_DUMMYGAME_HPP

#ifdef ENGINE_ONLY_MODE

#include <iostream>

#include "IGame.hpp"

namespace Engine
{

class PlayerModelComponent : public IEntityModelComponent
{
    void update(const IGameWorld& gameWorld) override
    {

    }

    bool isDestroyed() const override
    {
        return m_healthStat <= 0;
    }
private:
    int m_healthStat {10};
    int m_attackStat {5};
};

class PlayerInputComponent : public IEntityInputComponent
{
public:
    void update(const EntityInputInterface&, IEntityModelComponent&) const override
    {

    }
private:

};

class PlayerRenderComponent : public IEntityRenderComponent
{
    void update(const IEntityModelComponent&, EntityRenderInterface&) const override
    {

    }
};


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

    }
private:

};

class MonsterRenderComponent : public IEntityRenderComponent
{
    void update(const IEntityModelComponent&, EntityRenderInterface&) const override
    {

    }
};


class DummyEntityInputInterface : public EntityInputInterface
{
public:
    enum class Direction {Up, Right, Down, Left, None};

    Direction m_playerDirectionInput {Direction::None};
};

class DummyInputInterface : public IGameInputInterface
{
    const EntityInputInterface& getEntityInputInterface() const final {return entityInputInterface;}

    int mouseCoordinateX;
    int mouseCoordinateY;

private:
    DummyEntityInputInterface entityInputInterface;
};

class DummyEntityRenderInterface : public EntityRenderInterface
{
public:
    bool m_entitiesVisible;
};

class DummyRenderInterface : public IGameRenderInterface
{
    EntityRenderInterface& getEntityRenderInterface() final {return entityRenderInterface;}

    int outputScreenWidth;
    int outputScreenHeight;

private:
    DummyEntityRenderInterface entityRenderInterface;
};


class DummyGameWorld : public IGameWorld
{
public: 
    void updateWorldInputs(const IGameInputInterface& gameInputInterface) override
    {
        // std::cout << "World: CycleNo. " << cycleTimer << ": Game World reading Game Inputs" << std::endl;
    }

    void updateWorldModel() override
    {
        // std::cout << "World: CycleNo. " << cycleTimer << ": Game World updating" << std::endl;

        if (cycleTimer == 2)
        {
            Logging::logMessage("Creating a Monster");
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
        // std::cout << "World: CycleNo. " << cycleTimer << ": Game World writing to Game Renderer" << std::endl;
    }

private:
    int cycleTimer {0};
};


class DummyGame : public IGame
{
public:
    DummyGame(std::unique_ptr<IGameWorld> gameWorld) : IGame(std::move(gameWorld)) {}
    
	void init() final
    {
        Logging::logMessage("Game: Initializing game");
    }

    void tearDown() final
    {
        Logging::logMessage("Game: Tearing down game");
    }

    bool quitGame() final
    {
        if (cycleCount++ >= 10)
        {
            Logging::logMessage("Game: Quit condition reached");
            return true;
        }
        else return false;
    }

    const IGameInputInterface& getGameInputInterface() const final {return m_dummyInputInterface;}

    IGameRenderInterface& getGameRenderInterface() final {return m_dummyRenderInterface;}

private:
    int cycleCount {0};

    DummyInputInterface m_dummyInputInterface;
    DummyRenderInterface m_dummyRenderInterface;
};



} // namespace Engine

#endif // ENGINE_ONLY_MODE

#endif // ENGINE_DUMMYGAME_HPP