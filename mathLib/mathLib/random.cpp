#include "random.h"
#include "utils.h"

/*Default constructor*/
cMath::random::random()
{
}

cMath::random::random(int _seed)
{
	seed = _seed;
}

cMath::random::~random()
{
}

/*Should be a value with an even number of digits*/
void cMath::random::seedRand(int seedValue)
{
	seed = seedValue;
}

int cMath::random::getRandSeed()
{
	return seed;
}

void cMath::random::regenSeed()
{
	int seedSqr = cMath::pow(seed, 2);
	std::string strSeed = std::to_string(seedSqr);
	while (strSeed.length() < 6)
	{
		strSeed.insert(0, "0");
	}
	std::string trimmedStrSeed = "------";
	int j = 0;
	for (size_t i = strSeed.length() / 2 - 3; i < strSeed.length() / 2 + 3; i++)
	{
		trimmedStrSeed[j] = strSeed[i];
		j++;
	}
	seed = std::stoi(trimmedStrSeed, nullptr, 10);
	//std::cout << "New seed: " << seed << std::endl;
}