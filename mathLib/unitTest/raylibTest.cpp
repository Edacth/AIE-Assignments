#include "utils.h"
#include "raylib.h"
#include "vec2.h"
#include "vec3.h"
#include "transform2d.h"
#include <iostream>

int runRaylibTest()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (1600);
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	vec2 mousePos;
	transform2d character(
	100, 100, 0,
	0, 1, 0,
	10, 10, 1 );

	std::cout << "Rotation: " << (cMath::RAD_TO_DEG * character.localRotation()) << std::endl;

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		vec2 translationAxis = {0, 0};
		if (IsKeyDown(KEY_W))
		{
			translationAxis.y += -1;
		}
		if (IsKeyDown(KEY_S))
		{
			translationAxis.y += 1;
		}
		if (IsKeyDown(KEY_A))
		{
			translationAxis.x += -1;
		}
		if (IsKeyDown(KEY_D))
		{
			translationAxis.x += 1;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			character.rotate(1);
			std::cout << "Rotation: " << (RAD2DEG * character.localRotation()) << std::endl;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			character.rotate(-1);
			std::cout << "Rotation: " << (RAD2DEG * character.localRotation()) << std::endl;
		}
		if (translationAxis != vec2{0, 0})
		{
			character.translate(translationAxis);
		}
		//DrawLineV(character.localPosition(), (character.localPosition() + vec2(10, 10)), BLUE);
		
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		//DrawText(("Score " + (std::to_string(character.getTRSMatrix().m3))).c_str(), 100, 100, 20, BLACK);
		
		
		DrawCircleV(vec2(character.localPosition().x + character.localScale().x, character.localPosition().y + character.localScale().y), 3, RED);
		DrawCircleV(vec2(character.localPosition().x + character.localScale().x, character.localPosition().y - character.localScale().y), 3, RED);
		DrawCircleV(vec2(character.localPosition().x - character.localScale().x, character.localPosition().y - character.localScale().y), 3, RED);
		DrawCircleV(vec2(character.localPosition().x - character.localScale().x, character.localPosition().y + character.localScale().y), 3, RED);
		
		DrawCircleV(vec2(character.localPosition().x + character.getTRSMatrix().mm[1][0] * 20, character.localPosition().y + character.getTRSMatrix().mm[1][1] * 20), 3, BLUE);
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//-----------------------
	return 0;
}