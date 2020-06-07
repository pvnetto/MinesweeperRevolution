#pragma once
#include <vector>

namespace msrevo {
	namespace Math {
		/// <summary>
		/// Linear Interpolation for floats.
		/// </summary>
		inline float lerp(const float& a, const float& b, const float& t) {
			return (1 - t)*a + t * b;
		}

		/// <summary>
		/// Returns a random list of [count] integers between [0, n - 1],
		/// [excluded] can't be picked from the range.
		/// </summary>
		std::vector<int> sampleFromRange(int n, int count, int excluded);
	}
}