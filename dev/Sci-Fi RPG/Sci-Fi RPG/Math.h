#pragma once
#include <random>

namespace Math
{
	inline int dice(int min, int max)
	{
		// Random seed generator to roll d100s
		static std::mt19937 rng(std::random_device{}());
		std::uniform_int_distribution<int> chanceRoll(min, max);
		return chanceRoll(rng);
	}
};

