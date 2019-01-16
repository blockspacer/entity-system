// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "entity-system/model/base/attribute/AttributeBase.hpp"
#include "entity-system/model/base/type/TypeBase.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/validation/DataValidationBase.hpp"
#include "entity-system/util/error-handling/ReturnCodes.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {
    

	/// A base class for entity relation attribute types.
    class EntityRelationAttributeType : public TypeBase, public AttributeBase, public GUIDBase
    {
        public:

			/// Constructor.
			/// @param ent_rel_attr_type_name The name of the new entity relation attribute type.
			/// @param ent_rel_attr_type_data_type The data type of the new entity relation attribute type.
			/// @note the GUID of the new entity relation attribute type will
			/// be created automatically by the inheritance of GUIDBase!
			EntityRelationAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~EntityRelationAttributeType();

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
