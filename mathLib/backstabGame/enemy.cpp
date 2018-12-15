#undef PI
#include "utils.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::enemy(vec2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
}

enemy::enemy(vec2 _position, std::vector<GameObject*>* _gameObjects)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 30;
	rectangle.width = 30;
	gameObjectsPtr = _gameObjects;
	lookDir = { 3, 2 };
	
}

enemy::~enemy()
{
}

void enemy::update()
{
	directionToPlayer = *gameObjectsPtr->at(0)->getPosition() - position;

	normLookDir = lookDir.getNormalised();
	normDirectionToPlayer = directionToPlayer.getNormalised();
	rot = -atan2(normLookDir.x, normLookDir.y);
	
	
	float dotProduct = normDirectionToPlayer.dot(normLookDir);
	DrawText(std::to_string(dotProduct > 0.7f ? true : false).c_str(), 30, 30, 20, BLACK);
}

void enemy::draw()
{
	


	//float rot = -atan2(normDirectionToCursor.x, normDirectionToCursor.y);
	vec2 visionConeArm1 = { cos(rot + (45 * (float)cMath::DEG_TO_RAD)), sin(rot + (45 * (float)cMath::DEG_TO_RAD)) };
	vec2 visionConeArm2 = { cos(rot + (135 * (float)cMath::DEG_TO_RAD)), sin(rot + (135 * (float)cMath::DEG_TO_RAD)) };

	DrawLineV(position, (position + normLookDir.scale(80)), RED);
	DrawLineV(position, (position + visionConeArm1.normalise().scale(160)), GREEN);
	DrawLineV(position, (position + visionConeArm2.normalise().scale(160)), GREEN);
	DrawLineV(position, (position + normDirectionToPlayer.scale(160)), ORANGE);

	DrawRectanglePro({ position.x, position.y, rectangle.width, rectangle.height }, { rectangle.height / 2.0f, rectangle.width / 2.0f }, rot * cMath::RAD_TO_DEG, RED);


}