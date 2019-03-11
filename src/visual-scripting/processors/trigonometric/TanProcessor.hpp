#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/trigonometric/TanEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"
#include "logging/managers/LogManager.hpp"

#include "react/Event.h"

using namespace react;

namespace inexor {
namespace visual_scripting {

	using TanEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::TanEntityTypeProvider>;
	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// Processor which listens on the creation of entity instances
	/// of type TAN. Newly created entity instances of type TAN
	/// will be initialized by connecting the input attributes with
	/// a calculation function and the result with the output
	/// attribute.
    class TanProcessor
    	: public Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public std::enable_shared_from_this<TanProcessor>
    {

		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

			/// Constructs the TAN processor which listens on the creation
			/// of entity instances of type TAN. Newly created entity
			/// instances of type TAN will be initialized by connecting the
			/// input attributes with a calculation function and the result
			/// with the output attribute.
			TanProcessor(
				TanEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager,
				LogManagerPtr log_manager
			);

			~TanProcessor();

			/// Initializes the SIN processor by registering listeners
			/// on newly created entity instances of type SIN.
			void init();

			/// Called when an entity instance of type SIN has been created
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type SIN has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the processor signals.
			void make_signals(const EntityInstancePtr& entity_instance);

		private:

			/// The entity type provider for this processor
			TanEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The log manager
			LogManagerPtr log_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, SignalT<entity_system::DataValue> > signals;

			/// The event sources per entity instance.
			std::unordered_map<xg::Guid, EventSourceT<int> > event_sources;

			/// The event sources per entity instance.
			std::unordered_map<xg::Guid, SignalT<int> > current_time_iterators;

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.vs.p.t.tan";

    };

}
}
