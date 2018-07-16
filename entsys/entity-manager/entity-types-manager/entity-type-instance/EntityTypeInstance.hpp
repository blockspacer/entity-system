// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER

#include "../entity-type/EntityTypeEnum.hpp"

namespace inexor {
namespace entsys {

    /// \class CEntityTypeInstance
    /// \brief TODO
    class EntityTypeInstance
    {
        private:
             INEXOR_ENTSYS_ENTTYPE entity_type;
             
        public:
            EntityTypeInstance();
            ~EntityTypeInstance();
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER