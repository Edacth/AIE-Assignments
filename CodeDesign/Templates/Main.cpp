#include "Utils.h"
#include "GameObject.h"
#include "Ninja.h"
#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;


	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	std::cout << min(1, 3) << std::endl;
	std::cout << min(2.5, 4.66) << std::endl;
	std::cout << max(2.5, 4.66) << std::endl;
	Ninja ninja1 = {100, 100};
	Ninja ninja2 = { 100, 120 };
	Ninja ninja3 = { 100, 140 };

	GameObject<Ninja> dudes[] = { ninja1, ninja2, ninja3 };
	//dudes[0]->object

	std::cout << "meow" << std::endl;

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Dude " << i << " ";
			dudes[i].update();
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Dude " << i << " ";
			dudes[i].render();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------


	
	return 0;
}