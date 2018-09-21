// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& param_entity_type)
	{
		pointer_to_entity_type = param_entity_type;
		// TODO: Add pointer from EntityTypeInstanceManager's list!

	}


	EntityTypeInstance::EntityTypeInstance()
	{
		// TODO: Remove pointer from EntityTypeInstanceManager's list!
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
		// TODO: Remove pointer from EntityTypeInstanceManager's list!
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityTypeInstance::validate()
	{
		return ENTSYS_DATA_INVALID;
	}


};
};
