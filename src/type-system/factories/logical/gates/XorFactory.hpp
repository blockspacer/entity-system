#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

/// @class XorFactory
/// @brief Factory for creating entity instances of type XOR.
class XorFactory : public LifeCycleComponent
{
    public:
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// @brief Constructs a factory for creating entity instances of type XOR.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    XorFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~XorFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates an instance with default values
    EntityInstancePtrOpt create_instance();

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
