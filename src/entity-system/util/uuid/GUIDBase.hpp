#pragma once

#include <mutex>
#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class GUIDBase
	/// @brief A base class for globally unique identifiers (GUIDs).
	/// @note This implementation is based on crossguid.
	/// https://github.com/graeme-hill/crossguid
	class GUIDBase
	{
		private:

			/// The mutex of this class.
			std::mutex guid_base_mutex;

			/// The GUID of this class.
			xg::Guid globally_unique_identifier;

		protected:

			/// @brief Constructor.
			GUIDBase();

			/// @brief Copy Constructor.
			/// @param param_GUID The GUID which will be copied.
			GUIDBase(const xg::Guid& param_GUID);

			/// @brief Destructor.
			~GUIDBase();

		public:

			/// @brief Returns the GUID.
			/// @return The GUID.
			xg::Guid get_GUID() const;

			/// @brief Generates a new GUID.
			void generate_new_GUID();

	};

}
}
