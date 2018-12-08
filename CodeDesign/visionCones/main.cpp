#include "raylib.h"
#undef PI
#include "utils.h"
#include "vec2.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (1600);
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	vec2 mousePos;
	Vector2 myVector = { 30, 30 };
	vec2 boxSize(myVector);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		mousePos = GetMousePosition();

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangleV(mousePos, boxSize, RED);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//-----------------------
	return 0;
}