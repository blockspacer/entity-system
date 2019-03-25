#pragma once

#include "type-system/factories/logical/gates/NotFactory.hpp"
#include "type-system/factories/logical/gates/OrFactory.hpp"
#include "type-system/factories/logical/gates/AndFactory.hpp"
#include "type-system/factories/logical/gates/XorFactory.hpp"
#include "type-system/factories/logical/gates/NorFactory.hpp"
#include "type-system/factories/logical/gates/NandFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using NotFactoryPtr = std::shared_ptr<NotFactory>;
	using OrFactoryPtr = std::shared_ptr<OrFactory>;
	using AndFactoryPtr = std::shared_ptr<AndFactory>;
	using XorFactoryPtr = std::shared_ptr<XorFactory>;
	using NorFactoryPtr = std::shared_ptr<NorFactory>;
	using NandFactoryPtr = std::shared_ptr<NandFactory>;

	/// The factories for logical operations.
	class GateFactories
	{
		public:

			/// Constructs the factories for logical operations.
			GateFactories(
				NotFactoryPtr not_factory,
				OrFactoryPtr or_factory,
				AndFactoryPtr and_factory,
				XorFactoryPtr xor_factory,
				NorFactoryPtr nor_factory,
				NandFactoryPtr nand_factory
			);

			~GateFactories();

			/// Initializes the factories for logical operations.
			void init();

		private:

			/// Factory for creating entity instances of type NOT.
			NotFactoryPtr not_factory;

			/// Factory for creating entity instances of type OR.
			OrFactoryPtr or_factory;

			/// Factory for creating entity instances of type AND.
			AndFactoryPtr and_factory;

			/// Factory for creating entity instances of type XOR.
			XorFactoryPtr xor_factory;

			/// Factory for creating entity instances of type NOR.
			NorFactoryPtr nor_factory;

			/// Factory for creating entity instances of type NAND.
			NandFactoryPtr nand_factory;

	};

}
}
}