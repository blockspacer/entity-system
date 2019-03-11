#include "CosProcessor.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Observer.h"

#include "spdlog/spdlog.h"

using namespace std::chrono;

namespace inexor {
namespace visual_scripting {

	using CosEntityTypeProvider = entity_system::type_system::CosEntityTypeProvider;

	CosProcessor::CosProcessor(
		CosEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	CosProcessor::~CosProcessor()
	{
	}

	void CosProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void CosProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void CosProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void CosProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor COS for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_attr_cos_value = entity_instance->get_attribute_instance(CosEntityTypeProvider::COS_VALUE);
		if (o_attr_cos_value.has_value())
		{
			xg::Guid guid = entity_instance->get_GUID();
			std::shared_ptr<inexor::entity_system::EntityAttributeInstance> attr_cos_value = o_attr_cos_value.value();
		    std::thread start_thread([this, guid, attr_cos_value] () {

		    	// Create event source
				event_sources[guid] = MakeEventSource<entity_system::D, int>();

		    	// Hold last signal value
				current_time_iterators[guid] = Hold(event_sources[guid], 0);

				// Initialize the time iterator
		    	int time_iterator = 0;

				// Initialize the sinus resolution
			    float resolution = 10.0f;

			    // Create the signal
			    signals[guid] = MakeSignal(
					current_time_iterators[guid],
					[resolution] (int time_iterator)
					{
				    	float x_value = time_iterator / resolution;
						float y_value = cos(x_value);
						return entity_system::DataValue(y_value);
					}
				);

			    // Attach the signal to the signal_wrapper
				// o_attr_cos_value.value()->value = signals[guid];
			    attr_cos_value->signal_wrapper <<= signals[guid];

				// Loop while TODO
				while (true)
				{
					// Wait
					std::this_thread::sleep_for(50ms);

					// Increase time iterator
					time_iterator++;

					// Fire time iterator event
					this->event_sources[guid] << time_iterator;
				}
			});
		    start_thread.detach();
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing attribute {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), CosEntityTypeProvider::COS_VALUE);
		}
	}

};
};