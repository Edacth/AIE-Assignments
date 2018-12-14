#include "guard.h"
#include <string>

guard::guard()
{
	position = { 100, 100 };
	startingPosition = position;
	t = 0;
	lerpSpeed = 1.0;
	foundDestination = false;
}

guard::guard(vec2 _position)
{
	position = _position;
	startingPosition = position;
	t = 0;
	lerpSpeed = 1.0;
	foundDestination = false;
}

guard::~guard()
{
}

void guard::update()
{
	if (!foundDestination)
	{
		//if (lerpSpeed * GetFrameTime() < )
		{

		}
		position = cMath::lerp(startingPosition, destination->position, t);
		t += lerpSpeed * GetFrameTime();

		if (cMath::abs(position.x - destination->position.x) < 1 &&
			cMath::abs(position.y - destination->position.y) < 1)
		{
			foundDestination = true;
			destination = destination->nextPoint;
			t = 0;
			startingPosition = position;
		}
	}
	if (foundDestination)
	{
		
		foundDestination = false;
	}
	
}

void guard::draw()
{
	DrawRectangleV(position - vec2{5, 5}, { 10, 10 }, BLUE);
	DrawCircleV(destination->position, 7, RED);
	DrawText(std::to_string(t).c_str(), 30, 30, 20, BLACK);
}