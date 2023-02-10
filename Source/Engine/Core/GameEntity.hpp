

#ifndef ENGINE_IGAMEWORLD
#define ENGINE_IGAMEWORLD


#include <memory>
#include <vector>


namespace Engine
{


class EntityInputInterface
{

};


class EntityRenderInterface
{

};


class IGameWorld;
class IEntityModelComponent;


class IEntityInputComponent
{
public:
    virtual ~IEntityInputComponent() = default;

    // One game-cycle of logic to read the game's input interface and write to model component
    virtual void update(const EntityInputInterface&, IEntityModelComponent&) const = 0;
};


class IEntityModelComponent
{
public:
    virtual ~IEntityModelComponent() = default;

    // One game-cycle of logic to update the Entity Model
    virtual void update(const IGameWorld& gameWorld) = 0;

    // When this returns true, IGame will destroy the Entity which contains this Model
    virtual bool isDestroyed() const = 0;
};


class IEntityRenderComponent
{
public:
    virtual ~IEntityRenderComponent() = default;

    // One game-cycle of logic to read the game's model component and write to the render interfaces
    virtual void update(const IEntityModelComponent&, EntityRenderInterface&) const = 0;
};


class GameEntity
{
public:
    GameEntity(std::unique_ptr<IEntityInputComponent> input,
               std::unique_ptr<IEntityModelComponent> model,
               std::unique_ptr<IEntityRenderComponent> render) :
                    m_input{std::move(input)}, m_model{std::move(model)}, m_render{std::move(render)} {}

    virtual ~GameEntity() = default;

    void updateInputs(const EntityInputInterface& entityInputInterface)
    {
        if (m_input && m_model) m_input->update(entityInputInterface, *m_model);
    }

    void updateModel(const IGameWorld& gameWorld)
    {
        if (m_model) m_model->update(gameWorld);
    }

    void updateRenders(EntityRenderInterface& entityRenderInterface)
    {
        if (m_render && m_model) m_render->update(*m_model, entityRenderInterface);
    }

    bool isDestroyed() const
    {
        // Includes case where m_model pointer is nullptr (returns true)
        return (m_model ? m_model->isDestroyed() : true);
    }

private:
    std::unique_ptr<IEntityInputComponent> m_input;
    std::unique_ptr<IEntityModelComponent> m_model;
    std::unique_ptr<IEntityRenderComponent> m_render;
};


// class EntitySpawner
// {
// public:
//     virtual ~EntitySpawner() = default;

//     virtual std::unique_ptr<GameEntity> spawnEntity() = 0;

//     virtual std::unique_ptr<GameEntity> cloneEntity(const GameEntity& prototypeEntity) = 0;
// };


// template <typename EntityType>
// class SpawnerFor : public EntitySpawner
// {
// public:
//     std::unique_ptr<GameEntity> spawnEntity() final
//     {
//         return std::move(std::make_unique<EntityType>());
//     }

//     std::unique_ptr<GameEntity> cloneEntity(const GameEntity& prototypeEntity) final
//     {
//         return std::move(std::make_unique<EntityType>(prototypeEntity));
//     }
// };


} // namespace Engine


#endif // ENGINE_IGAMEWORLD
