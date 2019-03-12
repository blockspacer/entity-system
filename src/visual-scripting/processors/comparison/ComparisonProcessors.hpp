#pragma once

#include "visual-scripting/processors/comparison/EqualsBoolProcessor.hpp"
#include "visual-scripting/processors/comparison/EqualsIntProcessor.hpp"
#include "visual-scripting/processors/comparison/EqualsStringProcessor.hpp"
#include "visual-scripting/processors/comparison/GreaterThanIntProcessor.hpp"
#include "visual-scripting/processors/comparison/GreaterThanFloatProcessor.hpp"
#include "visual-scripting/processors/comparison/LowerThanIntProcessor.hpp"
#include "visual-scripting/processors/comparison/LowerThanFloatProcessor.hpp"
#include "visual-scripting/processors/comparison/InRangeIntProcessor.hpp"
#include "visual-scripting/processors/comparison/InRangeFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using EqualsBoolProcessorPtr = std::shared_ptr<EqualsBoolProcessor>;
	using EqualsIntProcessorPtr = std::shared_ptr<EqualsIntProcessor>;
	using EqualsStringProcessorPtr = std::shared_ptr<EqualsStringProcessor>;
	using GreaterThanIntProcessorPtr = std::shared_ptr<GreaterThanIntProcessor>;
	using GreaterThanFloatProcessorPtr = std::shared_ptr<GreaterThanFloatProcessor>;
	using LowerThanIntProcessorPtr = std::shared_ptr<LowerThanIntProcessor>;
	using LowerThanFloatProcessorPtr = std::shared_ptr<LowerThanFloatProcessor>;
	using InRangeIntProcessorPtr = std::shared_ptr<InRangeIntProcessor>;
	using InRangeFloatProcessorPtr = std::shared_ptr<InRangeFloatProcessor>;

    /// Provides the processors for comparison operations.
	class ComparisonProcessors
	{
		public:

			/// Constructs the processors for comparison operations.
			ComparisonProcessors(
				EqualsBoolProcessorPtr equals_bool_processor,
				EqualsIntProcessorPtr equals_int_processor,
				EqualsStringProcessorPtr equals_string_processor,
				GreaterThanIntProcessorPtr greater_than_int_processor,
				GreaterThanFloatProcessorPtr greater_than_float_processor,
				LowerThanIntProcessorPtr lower_than_int_processor,
				LowerThanFloatProcessorPtr lower_than_float_processor,
				InRangeIntProcessorPtr in_range_int_processor,
				InRangeFloatProcessorPtr in_range_float_processor
			);

			~ComparisonProcessors();

			/// Initialization of the processors for comparison operations.
			void init();

		private:

			// Processor for the entity type EQUALS_BOOL
			EqualsBoolProcessorPtr equals_bool_processor;

			// Processor for the entity type EQUALS_INT
			EqualsIntProcessorPtr equals_int_processor;

			// Processor for the entity type EQUALS_STRING
			EqualsStringProcessorPtr equals_string_processor;

			// Processor for the entity type GREATER_THAN_INT
			GreaterThanIntProcessorPtr greater_than_int_processor;

			// Processor for the entity type GREATER_THAN_FLOAT
			GreaterThanFloatProcessorPtr greater_than_float_processor;

			// Processor for the entity type LOWER_THAN_INT
			LowerThanIntProcessorPtr lower_than_int_processor;

			// Processor for the entity type LOWER_THAN_FLOAT
			LowerThanFloatProcessorPtr lower_than_float_processor;

			// Processor for the entity type IN_RANGE_INT
			InRangeIntProcessorPtr in_range_int_processor;

			// Processor for the entity type IN_RANGE_FLOAT
			InRangeFloatProcessorPtr in_range_float_processor;

	};

}
}
