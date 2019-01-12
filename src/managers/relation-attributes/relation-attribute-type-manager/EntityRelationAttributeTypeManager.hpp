// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include "../../manager-templates/TypeManagerTemplate.hpp"
#include "../../../util/type-definitions/TypeDefinitions.hpp"
#include "../../../model/relation-attributes/relation-attribute-types/EntityRelationAttributeType.hpp"
#include "../../../model/relation-attributes/relation-attribute-instances/EntityRelationAttributeInstance.hpp"


namespace inexor {
namespace entity_system {

	
	/// A manager class for entity relation attribute types.
	class EntityRelationAttributeTypeManager : public TypeManagerTemplate<EntityRelationAttributeType>
	{
		private:

			/// This entity relation attribute type error will be returned when a method fails.
			const ENT_REL_ATTR_TYPE entity_relation_attribute_type_error = std::make_shared<EntityRelationAttributeType>("ERROR", ENTSYS_DATA_TYPE_UNDEFINED);

		protected:

			/// Constructor.
			EntityRelationAttributeTypeManager();

			/// Destructor.
			~EntityRelationAttributeTypeManager();

		public:

			/// Creates an entity relation attribute type.
			/// @param ent_rel_attr_type_name The name of the new entity relation attribute type.
			/// @param ent_rel_attr_data_type The data type of the new entity relation attribute type.
			/// @return A shared pointer to the entity relation attribute type which was created.
			/// <br>If this method fails, entity_relation_attribute_type_error will be returned as error object.
			ENT_REL_ATTR_TYPE create_entity_relation_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Returns the number of existing types of entity relation attributes.
			/// @return The number of existing types of entity relation attributes.
			std::size_t get_entity_relation_attribute_type_count() const;

			/// Deletes all types of entity relation attributes.
			void delete_all_entity_relation_attribute_types();

	};


};
};