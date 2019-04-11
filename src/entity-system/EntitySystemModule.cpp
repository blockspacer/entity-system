#include "EntitySystemModule.hpp"

namespace inexor {
namespace entity_system {

	EntitySystemModule::EntitySystemModule(
		EntityManagerPtr entity_manager,
		RelationManagerPtr relation_manager,
		BuilderFactoryManagerPtr builder_factory_manager
	)
		: entity_manager(entity_manager),
		relation_manager(relation_manager),
		builder_factory_manager(builder_factory_manager)
	{
	}

	EntitySystemModule::~EntitySystemModule()
	{
	}

	void EntitySystemModule::reset_entity_system()
	{
		relation_manager->reset_entity_system();
		entity_manager->reset_entity_system();
	}

}
}
