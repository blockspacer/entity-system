// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-manager/entity-relation-type/EntityRelationType.hpp"
#include "../../templates/TypeManager.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for types of entity relations.
    class EntityRelationTypeManager : public TypeManager<EntityRelationType>
    {
		private:

			/// This entity relation error type will be returned when a method fails.
			ENT_REL_TYPE entity_relation_type_error = std::make_shared<EntityRelationType>("ERROR", nullptr, nullptr);

        protected:

			/// Constructor.
			EntityRelationTypeManager();

			/// Destructor.
			~EntityRelationTypeManager();

		public:

			/// Checks if an entity relation type does already exist.
			/// @param ? TODO
			bool does_entity_relation_type_exist(const std::string&);

			/// Checks if an entity relation type does already exist.
			/// @param ? TODO
			bool does_entity_relation_type_exist(const ENT_REL_TYPE&);

			// TODO: check by UUID!

			/// Creates a new entity relation type and store it in the entity system.
			/// @param ? TODO
			/// @param ? TODO
			/// @param ? TODO
			ENT_REL_TYPE create_entity_relation_type(const std::string&, const ENT_TYPE&, const ENT_TYPE&);

			/// Returns the number of available entity relation types.
			const std::size_t get_entity_relation_types_count() const;

			/// Deletes an entity relation type.
			/// @param ? TODO
			void delete_entity_relation_type(const std::string&);
			
			/// Deletes an entity relation type.
			/// @param ? TODO
			void delete_entity_relation_type(const ENT_REL_TYPE&);

			// TODO: Delete by UUID.

			/// Deletes all entity relation types.
			void delete_all_entity_relation_types();

	};

};
};