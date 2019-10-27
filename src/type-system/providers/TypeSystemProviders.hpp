#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/data/DataProviders.hpp"
#include "type-system/providers/generators/GeneratorProviders.hpp"
#include "type-system/providers/inout/InOutProviders.hpp"
#include "type-system/providers/logical/LogicalProviders.hpp"
#include "type-system/providers/math/MathProviders.hpp"

namespace inexor::entity_system::type_system {

using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
using DataProvidersPtr = std::shared_ptr<DataProviders>;
using GeneratorProvidersPtr = std::shared_ptr<GeneratorProviders>;
using InOutProvidersPtr = std::shared_ptr<InOutProviders>;
using MathProvidersPtr = std::shared_ptr<MathProviders>;
using LogicalProvidersPtr = std::shared_ptr<LogicalProviders>;

/// @class TypeSystemProviders
/// @brief The providers of the type system.
class TypeSystemProviders
{
    public:
    /// @brief Constructs the providers of the type system.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_factory Factory for creating entity types.
    /// @param data_providers The providers for constants and stores.
    /// @param generator_providers The providers for generators.
    /// @param in_out_providers The providers for input and output.
    /// @param math_providers The providers for mathematical operations.
    /// @param logical_providers The providers for logical operations.
    TypeSystemProviders(EntityTypeBuilderFactoryPtr entity_type_builder_factory, DataProvidersPtr data_providers, GeneratorProvidersPtr generator_providers, InOutProvidersPtr in_out_providers, MathProvidersPtr math_providers,
                        LogicalProvidersPtr logical_providers);

    /// Destructor.
    ~TypeSystemProviders();

    /// Initializes the providers of the type system.
    void init();

    private:
    /// Factory for creating entity types.
    EntityTypeBuilderFactoryPtr entity_type_builder_factory;

    /// The providers for constants and stores.
    DataProvidersPtr data_providers;

    /// The providers for generators.
    GeneratorProvidersPtr generator_providers;

    /// The providers for input and output.
    InOutProvidersPtr in_out_providers;

    /// The providers for mathematical operations.
    MathProvidersPtr math_providers;

    /// The providers for logical operations.
    LogicalProvidersPtr logical_providers;
};

} // namespace inexor::entity_system::type_system
