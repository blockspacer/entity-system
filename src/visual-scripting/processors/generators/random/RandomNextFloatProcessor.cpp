#include "RandomNextFloatProcessor.hpp"

#include <utility>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

#include "react/Algorithm.h"

#include "spdlog/spdlog.h"

namespace inexor::visual_scripting {

using RandomNextFloatEntityTypeProvider = entity_system::type_system::RandomNextFloatEntityTypeProvider;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

using DataValue = entity_system::DataValue;
using DataType = entity_system::DataType;

RandomNextFloatProcessor::RandomNextFloatProcessor(const RandomNextFloatEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(entity_type_provider->get_type()), entity_type_provider(entity_type_provider), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

RandomNextFloatProcessor::~RandomNextFloatProcessor() = default;

void RandomNextFloatProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
}

void RandomNextFloatProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
{
    make_signals(entity_instance);
}

void RandomNextFloatProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void RandomNextFloatProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance> &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor RANDOM_NEXT_FLOAT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    EntityAttributeInstancePtrOpt o_attr_random_next_float_on_activation = entity_instance->get_attribute_instance(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_ON_ACTIVATION);
    EntityAttributeInstancePtrOpt o_attr_random_next_float_min = entity_instance->get_attribute_instance(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MIN);
    EntityAttributeInstancePtrOpt o_attr_random_next_float_max = entity_instance->get_attribute_instance(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MAX);
    EntityAttributeInstancePtrOpt o_attr_random_next_float_value = entity_instance->get_attribute_instance(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_VALUE);

    if (o_attr_random_next_float_on_activation.has_value() && o_attr_random_next_float_min.has_value() && o_attr_random_next_float_max.has_value() && o_attr_random_next_float_value.has_value())
    {
        xg::Guid guid = entity_instance->get_GUID();

        // Create the signal
        signals[guid] =
            MakeSignal(With(o_attr_random_next_float_on_activation.value()->value, o_attr_random_next_float_min.value()->value, o_attr_random_next_float_max.value()->value), [this](DataValue on_activation, DataValue min, DataValue max) {
                std::mt19937 random_generator(random_device());
                std::uniform_real_distribution<float> dist(std::get<DataType::FLOAT>(min), std::get<DataType::FLOAT>(max));
                return DataValue(dist(random_generator));
            });

        // Attach the signal to the signal_wrapper
        // o_attr_random_next_float_value.value()->value = signals[guid];
        o_attr_random_next_float_value.value()->signal_wrapper <<= signals[guid];

    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_ON_ACTIVATION, RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MIN, RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MAX,
                    RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_VALUE);
    }
}

} // namespace inexor::visual_scripting
