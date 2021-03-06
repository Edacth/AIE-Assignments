#include "utils.h"
#include "raylib.h"
#include "vec2.h"
#include "vec3.h"
#include "raylibTest.h"
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
	transform2d character (
		{100, 100}, 0, {10, 10});
	transform2d turret(
		{30, 30}, 0, {1, 1});
	transform2d test(
		{ 10, 0 }, 0, { 1, 1 });
	turret.setParent(&character);

	//std::cout << "Rotation: " << (cMath::RAD_TO_DEG * character.localRotation()) << std::endl;

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
		if (IsKeyDown(KEY_RIGHT))
		{
			character.rotate(cMath::DEG_TO_RAD * 1);
		}
		if (IsKeyDown(KEY_LEFT))
		{
			character.rotate(cMath::DEG_TO_RAD * -1);
		}
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			character.lookAt(GetMousePosition());
		}
		if (translationAxis != vec2{0, 0})
		{
			character.translate(translationAxis);
		}


		vec2 charPos = character.getLocalPosition();
		float charRot = character.getLocalRotation();
		vec2 charScale = character.getLocalScale();

		vec2 turretPos = turret.worldPosition();
		//DrawLineV(character.getLocalPosition(), (character.getLocalPosition() + vec2(10, 10)), BLUE);
		
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		

		DrawText(("Rotation: " + (std::to_string(charRot))).c_str(), 10, 10, 20, BLACK);

		DrawCircleV(vec2(charPos.x +charScale.x, charPos.y +charScale.y), 3, RED);
		DrawCircleV(vec2(charPos.x +charScale.x, charPos.y -charScale.y), 3, RED);
		DrawCircleV(vec2(charPos.x -charScale.x, charPos.y -charScale.y), 3, RED);
		DrawCircleV(vec2(charPos.x -charScale.x, charPos.y +charScale.y), 3, RED);
		
		DrawCircleV(charPos + character.getForward() * 20, 3, BLUE);
		
		DrawCircleV(turretPos, 3, GREEN);
		
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//-----------------------
	return 0;
}