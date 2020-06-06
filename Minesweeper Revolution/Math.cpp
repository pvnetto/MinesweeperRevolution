#include "Math.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <random>
#include <unordered_set>

std::unordered_set<int> pickSet(int size, int randCount, std::mt19937& gen) {
	std::uniform_int_distribution<> dis(1, size);
	std::unordered_set<int> elems;

	while (elems.size() < randCount) {
		elems.insert(dis(gen));
	}

	return elems;
}

std::vector<int> msrevo::Math::sampleFromRange(int size, int randCount) {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::unordered_set<int> elems = pickSet(size - 1, randCount, gen);

	std::vector<int> result(elems.begin(), elems.end());
	std::shuffle(result.begin(), result.end(), gen);
	return result;
}
