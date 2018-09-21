// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

// Instances of types of attributes of entities.
#include "../../entity-manager/entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
using namespace inexor::entity_system;


TEST(EntityAttributeTypeInstanceTests, get_entity_attribute_data_type)
{
	std::string ent_attr_name = "density";
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_FLOAT;
	ENT_ATTR_TYPE new_ent_attr1 = CREATE_ENT_ATTR_TYPE(ent_attr_name, ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_type_name(), ent_attr_name);

	ENT_ATTR_TYPE_INSTANCE new_ent_attr1_inst = CREATE_ENT_ATTR_TYPE_INSTANCE(new_ent_attr1);
	EXPECT_EQ(new_ent_attr1_inst->get_entity_attribute_data_type(), ent_attr_data_type);
}


TEST(EntityAttributeTypeInstanceTests, get_entity_attribute_type_name)
{
	std::string ent_attr_name = "weight";
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_FLOAT;
	ENT_ATTR_TYPE new_ent_attr1 = CREATE_ENT_ATTR_TYPE(ent_attr_name, ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_type_name(), ent_attr_name);

	ENT_ATTR_TYPE_INSTANCE new_ent_attr1_inst = CREATE_ENT_ATTR_TYPE_INSTANCE(new_ent_attr1);
	EXPECT_EQ(new_ent_attr1_inst->get_entity_attribute_data_type(), ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1_inst->get_entity_attribute_type_name(), ent_attr_name);
}
