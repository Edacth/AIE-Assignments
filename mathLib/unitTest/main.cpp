#include <iostream>
#include "utils.h"

int main()
{

	int minVal = cMath::min(2, 3);
	std::cout << minVal << std::endl;

	int maxVal = cMath::max(2, -1);
	std::cout << maxVal << std::endl;

	int clampVal = cMath::clamp(122, 4, 10);
	std::cout << clampVal << std::endl;

	std::cout << 6 * cMath::DEG_TO_RAD << std::endl;

	std::cout << 6 * cMath::RAD_TO_DEG << std::endl;

	std::cout << cMath::abs(-5) << std::endl;
	std::cout << cMath::abs(5) << std::endl;
	std::cout << cMath::abs(0) << std::endl;

	std::cout << cMath::pow(5, 5) << std::endl;
	std::cout << cMath::pow(5, 0) << std::endl;

	std::cout << cMath::isPowerOfTwo(34) << std::endl;


	return 0;
}