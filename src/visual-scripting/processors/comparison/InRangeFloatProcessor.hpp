#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/comparison/InRangeFloatEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace react;

	/// Processor for entity instances of type IN_RANGE_FLOAT.
    class InRangeFloatProcessor
    	: public Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public std::enable_shared_from_this<InRangeFloatProcessor>
    {

    	using InRangeFloatEntityTypeProviderPtr = std::shared_ptr<inexor::entity_system::type_system::InRangeFloatEntityTypeProvider>;
    	using EntityInstanceManagerPtr = std::shared_ptr<inexor::entity_system::EntityInstanceManager>;
    	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
    	using EntityInstancePtr = std::shared_ptr<inexor::entity_system::EntityInstance>;

		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

    		/// @brief Constructs a new entity instance of type IN_RANGE_FLOAT.
			InRangeFloatProcessor(
				InRangeFloatEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager,
				LogManagerPtr log_manager
			);

			~InRangeFloatProcessor();

			/// Initialization of the processor.
			void init();

			/// Called when an entity instance of type IN_RANGE_FLOAT has been created
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type IN_RANGE_FLOAT has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the processor signals.
			void make_signals(const EntityInstancePtr& entity_instance);

		private:

			/// The entity type provider for this active component.
			InRangeFloatEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The log manager
			LogManagerPtr log_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, SignalT<entity_system::DataValue> > signals;

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.vs.p.c.irf";

    };

}
}
