#include "raylib.h"
#include "sprite.h"
#include "button.h"
#include <string>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;


	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Sprite sprite1 = { {"adventurer_climb"}, 2, 5 };
	Button button1 = { "red_button", 3, 100, 100 };
	Button button2 = { "green_button", 3, 200, 100 };
	Button button3 = { "blue_button", 3, 150, 200 };

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_A))
		{
			sprite1.x--;
		}
		if (IsKeyDown(KEY_D))
		{
			sprite1.x++;
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		button1.Draw();
		button2.Draw();
		button3.Draw();

		//sprite1.Draw();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	
	return 0;
}