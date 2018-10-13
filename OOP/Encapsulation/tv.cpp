#include <iostream>
#include "tv.h"

void tv::increaseVolume()
{
	currentVolume++;
}
void tv::decreaseVolume()
{
	currentVolume--;
}

void tv::increaseChannel()
{
	currentChannel++;
}
void tv::decreaseChannel()
{
	currentChannel--;
}

int tv::volume()
{
	return currentVolume;
}

int tv::channel()
{
	return currentChannel;
}