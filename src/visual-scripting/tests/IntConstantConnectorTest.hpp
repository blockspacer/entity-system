#pragma once

#include "type-system/factories/arithmetic/AddIntFactory.hpp"
#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace visual_scripting {

	/// @class IntConstantConnectorTest
    /// @brief Tests for connecting INT_CONSTANT entity instances
	class IntConstantConnectorTest
	{
		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

			using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
			using IntConstantFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::IntConstantFactory>;
			using AddIntFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::AddIntFactory>;
			using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
			using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
			using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

			/// @brief Constructor.
			IntConstantConnectorTest(
				ConnectorManagerPtr connector_manager,
				IntConstantFactoryPtr int_constant_factory,
				AddIntFactoryPtr add_int_factory,
				LogManagerPtr log_manager
			);

			/// @brief Destructor.
			~IntConstantConnectorTest();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void run_connector_tests();

		private:

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// Factory for INT_CONSTANT
			IntConstantFactoryPtr int_constant_factory;

			/// Factory for ADD_INT
			AddIntFactoryPtr add_int_factory;

			/// The log manager
			LogManagerPtr log_manager;

			/// The entity instance for the logger.
			EntityInstancePtrOpt o_logger;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.vs.test.intconst";

			/// The name of the source.
			static constexpr char SOURCE_NAME[] = "source";
			static int SOURCE_INITIAL_VALUE;

			/// The name of the first target.
			static constexpr char TARGET_1_NAME[] = "target1";
			static int TARGET_1_INITIAL_VALUE;

			/// The name of the second target.
			static constexpr char TARGET_2_NAME[] = "target2";
			static int TARGET_2_INITIAL_VALUE;

			/// The name of the third target.
			static constexpr char TARGET_3_NAME[] = "target3";
			static int TARGET_3_INITIAL_VALUE;

			/// The name of the add int.
			static constexpr char ADD_INT_NAME[] = "add_int";

			void log_create_entity_instance(std::string entity_instance_name, int initial_value);

			void log_create_connector(std::string output_entity_instance_name, std::string output_entity_attr_name, std::string input_entity_instance_name, std::string input_entity_attr_name);

			void log_attr(std::string entity_instance_name, std::string entity_attr_name, EntityAttributeInstancePtr entity_attribute_instance);

			void log_data_value(std::string prefix, std::string entity_instance_name, std::string entity_attr_name, entity_system::DataValue data_value);

			void enable_connector_debug(ConnectorPtrOpt connector);

	};

}
}
