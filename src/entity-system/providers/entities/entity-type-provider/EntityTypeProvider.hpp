// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {

	using AttributeList = unordered_map<string, ENTSYS_DATA_TYPE>;

	/// @class EntityTypeProvider
    /// @brief Provides the entity type.
	class EntityTypeProvider
	{
		public:

			/// Constructor.
			EntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager,
				string entity_type_name,
				AttributeList entity_type_attributes
			);

			/// Destructor.
			~EntityTypeProvider();

			/// Returns the entity type
			string get_type_name();

			/// Returns the entity type
			shared_ptr<EntityType> get_type();

		private:

			/// The entity type builder manager
			shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager;

			/// The entity type name
			string entity_type_name;

			/// The list of attributes of the entity type
			AttributeList entity_type_attributes;

			/// The entity type
			shared_ptr<EntityType> entity_type;

			/// True, if the entity type has been created
			bool created;
	};


};
};
