#pragma once
#include <vector>

namespace msrevo {
	namespace Math {
		inline float lerp(const float& a, const float& b, const float& t) {
			return (1 - t)*a + t * b;
		}

		std::vector<int> sampleFromRange(int n, int count, int excluded);
	}
}