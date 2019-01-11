#include "raylib.h"
#undef PI
#include "vec2.h"
#include "vec3.h"
#include "transform2d.h"
#include "tank.h"
#include "turret.h"
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
	turret turret({ 0, 0 }, tankTextures[1]);
	turret.transform.setParent(&(character.transform));

	//std::cout << "Rotation: " << (cMath::RAD_TO_DEG * character.localRotation()) << std::endl;

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		character.update();
		turret.update();


		vec2 charPos = character.transform.getLocalPosition();
		float charRot = character.transform.getLocalRotation();
		vec2 charScale = character.transform.getLocalScale();

		vec2 tankPos = character.transform.worldPosition();
		vec2 turretPos = turret.transform.worldPosition();
		//DrawLineV(character.getLocalPosition(), (character.getLocalPosition() + vec2(10, 10)), BLUE);

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//DrawText(("Turret: " + (std::to_string(turret.transform.getLocalPosition().x))).c_str(), 10, 10, 20, BLACK);

		character.draw();
		turret.draw();
		//DrawCircleV(turretPos, 3, RED);

		//DrawCircleV(charPos + character.transform.getForward() * 20, 3, BLUE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //-----------------------
	return 0;
}