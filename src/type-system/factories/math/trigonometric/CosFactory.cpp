#include "CosFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	CosFactory::CosFactory(
		CosEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	CosFactory::~CosFactory()
	{
	}

	void CosFactory::init()
	{
	}

	EntityInstancePtrOpt CosFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(CosEntityTypeProvider::COS_INPUT, 0.0f)
			->attribute(CosEntityTypeProvider::COS_VALUE, 1.0f)
			->build();
	}

	EntityInstancePtrOpt CosFactory::create_instance(float input_value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(CosEntityTypeProvider::COS_INPUT, input_value)
			->attribute(CosEntityTypeProvider::COS_VALUE, cosf(input_value))
			->build();
	}

}
}
}