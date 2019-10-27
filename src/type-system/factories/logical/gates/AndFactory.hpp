#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/gates/AndEntityTypeProvider.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

/// @class AndFactory
/// @brief Factory for creating entity instances of type AND.
class AndFactory
{
    public:
    using AndEntityTypeProviderPtr = std::shared_ptr<AndEntityTypeProvider>;
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// @brief Constructs a factory for creating entity instances of type AND.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type AND.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    AndFactory(AndEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~AndFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values
    EntityInstancePtrOpt create_instance();

    private:
    /// Provides the entity type AND.
    AndEntityTypeProviderPtr entity_type_provider;

    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
