#include "Math.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <random>
#include <unordered_set>

std::unordered_set<int> pickSet(int rangeSize, int randCount, int excluded, std::mt19937& gen) {
	std::uniform_int_distribution<> dis(0, rangeSize);
	std::unordered_set<int> elems;

	while (elems.size() < randCount) {
		int newEl = dis(gen);
		if (newEl != excluded) {
			elems.insert(newEl);
		}
	}

	return elems;
}

std::vector<int> msrevo::Math::sampleFromRange(int size, int randCount, int excluded) {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::unordered_set<int> elems = pickSet(size - 1, randCount, excluded, gen);

	std::vector<int> result(elems.begin(), elems.end());
	std::shuffle(result.begin(), result.end(), gen);
	return result;
}
