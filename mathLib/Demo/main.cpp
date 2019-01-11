#include "raylib.h"
#undef PI
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "transform2d.h"
#include "tank.h"
#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (1600);
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	vec2 mousePos;
	Texture2D tankTextures[2] = {
		{ LoadTexture("resources//tankBody_green.png") },
		{ LoadTexture("resources//tankGreen_barrel2_outline.png") } };
	tank character({ 100, 100 }, tankTextures[0]);
	transform2d turret(
		{ 0, 0 }, 0, { 1, 1 });
	turret.setParent(&(character.transform));

	//std::cout << "Rotation: " << (cMath::RAD_TO_DEG * character.localRotation()) << std::endl;

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		vec2 translationAxis = { 0, 0 };
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
			character.transform.rotate(cMath::DEG_TO_RAD * 1);
		}
		if (IsKeyDown(KEY_LEFT))
		{
			character.transform.rotate(cMath::DEG_TO_RAD * -1);
		}
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			character.transform.lookAt(GetMousePosition());
		}
		if (translationAxis != vec2{ 0, 0 })
		{
			character.transform.translate(translationAxis);
		}


		vec2 charPos = character.transform.getLocalPosition();
		float charRot = character.transform.getLocalRotation();
		vec2 charScale = character.transform.getLocalScale();

		vec2 turretPos = turret.worldPosition();
		//DrawLineV(character.getLocalPosition(), (character.getLocalPosition() + vec2(10, 10)), BLUE);

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);



		DrawText(("Rotation: " + (std::to_string(charRot))).c_str(), 10, 10, 20, BLACK);

		DrawCircleV(vec2(charPos.x + charScale.x, charPos.y + charScale.y), 3, RED);
		DrawCircleV(vec2(charPos.x + charScale.x, charPos.y - charScale.y), 3, RED);
		DrawCircleV(vec2(charPos.x - charScale.x, charPos.y - charScale.y), 3, RED);
		DrawCircleV(vec2(charPos.x - charScale.x, charPos.y + charScale.y), 3, RED);

		DrawCircleV(charPos + character.transform.getForward() * 20, 3, BLUE);

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