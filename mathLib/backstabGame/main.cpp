#include "raylib.h"
#undef PI
#include "utils.h"
#include "vec2.h"
#include "GameObject.h"
#include "player.h"
#include "enemy.h"
#include <vector>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (1600);
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	vec2 mousePos;


	std::vector<GameObject*> gameObjects;
	player basePlayer = { { 200 ,200 }, &gameObjects };
	player* basePlayerPtr = &basePlayer;
	enemy baseEnemy = { { 300 ,300 }, &gameObjects };
	enemy* baseEnemyPtr = &baseEnemy;
	gameObjects.push_back(basePlayerPtr);
	gameObjects.push_back(baseEnemyPtr);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		mousePos = GetMousePosition();
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->update();
		}

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//-----------------------
	return 0;
}