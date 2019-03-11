#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/factories/trigonometric/SinFactory.hpp"
#include "type-system/factories/trigonometric/CosFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "renderer/factories/RendererFactory.hpp"
#include "logging/managers/LogManager.hpp"

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using SinFactoryPtr = std::shared_ptr<entity_system::type_system::SinFactory>;
	using CosFactoryPtr = std::shared_ptr<entity_system::type_system::CosFactory>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using RendererFactoryPtr = std::shared_ptr<RendererFactory>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

	/// @class RendererManager
    /// @brief Management of the rendering.
    class RendererManager
    	: public std::enable_shared_from_this<RendererManager>
    {
		public:

			/// Constructor.
			RendererManager(
				EntityInstanceManagerPtr entity_instance_manager,
				ConnectorManagerPtr connector_manager,
				SinFactoryPtr sin_factory,
				CosFactoryPtr cos_factory,
				RendererFactoryPtr render_factory,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~RendererManager();

			/// Initialize renderer.
			void init();

			/// Starts the window thread.
			void start_window_thread(GLFWwindow *windows);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.r.manager";

		private:

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The sin factory
			SinFactoryPtr sin_factory;

			/// The sin factory
			CosFactoryPtr cos_factory;

			/// The connector manager
			ConnectorManagerPtr connector_manager;

			/// The entity type provider
			RendererFactoryPtr renderer_factory;

			/// The log manager
			LogManagerPtr log_manager;

			/// The renderer entity instance.
			EntityInstancePtr renderer;

			/// The sinus generator.
			EntityInstancePtr sin_x;

			/// The sinus generator.
			EntityInstancePtr cos_y;

			/// The attribute sin_value
			EntityAttributeInstancePtr sin_x_attr_value;

			/// The attribute cos_value
			EntityAttributeInstancePtr cos_y_attr_value;

			/// The attribute renderer_x
			EntityAttributeInstancePtr renderer_x_attr_value;

			/// The attribute renderer_x
			EntityAttributeInstancePtr renderer_y_attr_value;

    };

}
}