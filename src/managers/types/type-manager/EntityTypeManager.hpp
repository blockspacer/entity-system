// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "../../manager-templates/TypeManagerTemplate.hpp"
#include "../../../model/types/types/EntityType.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity types.
	class EntityTypeManager : public TypeManagerTemplate<EntityType>
	{
		private:

			/// This entity type error will be returned when a method fails.
			const ENT_TYPE entity_type_error = std::make_shared<EntityType>("ERROR");

		protected:

			/// Constructor.
			EntityTypeManager();

			/// Destructor.
			~EntityTypeManager();
		
		public:

			/// Checks if an entity type does already exist.
			/// @param ent_type_name The name of the entity type.
			/// @return True if the entity type does already exist,
			/// false otherwise.
			bool does_entity_type_exist(const std::string&);
			
			/// Checks if an entity type does already exist.
			/// @param ent_type A const reference of
			/// a shared pointer to the entity type.
			/// @return True if the entity type does already exist,
			/// false otherwise.
			bool does_entity_type_exist(const ENT_TYPE&);

			/// Checks if an entity type does already exist.
			bool does_entity_type_exist(const xg::Guid&);

			/// Creates a new entity type.
			/// @param ent_type_name The name of the new entity type.
			/// @return A shared pointer to the entity type which was created.
			/// <br>If this method fails, entity_type_error will be returned as error object.
			ENT_TYPE create_entity_type(const std::string&);

			/// Returns the number of existing entity types.
			/// @return The number of existing entity types.
			std::size_t get_entity_type_count() const;
			
			/// Deletes an entity type by name.
			/// @param ent_type_name The name of the entity type which will be deleted.
			void delete_entity_type(const std::string&);

			/// Deletes an entity type by entity type.
			/// @param ent_type A const reference of a shared pointer
			/// to the entity type which will be deleted.
			void delete_entity_type(const ENT_TYPE&);
			
			/// Deletes an entity type by GUID.
			void delete_entity_type(const xg::Guid&);

			/// Removes all types of entities.
			void delete_all_entity_types();

	};


};
};