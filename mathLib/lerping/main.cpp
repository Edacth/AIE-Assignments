#include "raylib.h"
#undef PI;
#include "utils.h"
#include "vec2.h"
#include "guard.h"
#include "waypoint.h"
#include "healthBar.h"
#include <string>


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (1600);
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	guard guard1;
	int waypointArrSize = 3;
	waypoint* waypointArr = new waypoint[waypointArrSize];
	waypointArr[0] = { vec2{200, 180}, &waypointArr[1] };
	waypointArr[1] = { vec2{500, 200}, &waypointArr[2] };
	waypointArr[2] = { vec2{1000, 400}, &waypointArr[0] };

	guard1.destination = &waypointArr[0];

	healthBar mainBar = { {100, 600} };
	int maxHealth = 250;
	int health = maxHealth;

	vec2* bezierCurve = new vec2[4];
	bezierCurve[0] = {400, 500};
	bezierCurve[1] = {500, 600};
	bezierCurve[2] = {600, 500};
	bezierCurve[3] = {800, 300};
	
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		guard1.update();
		if (IsKeyDown(KEY_A))
		{
			health--;
		}
		if (IsKeyDown(KEY_D))
		{
			health++;
		}
		mainBar.update(health, maxHealth);
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		guard1.draw();
		
		DrawText(std::to_string(health).c_str(), 800, 570, 20, BLACK);
		mainBar.draw();
		for (size_t i = 0; i < waypointArrSize; i++)
		{
			waypointArr[i].draw();
		}

		for (size_t i = 0; i < 4; i++)
		{
			DrawCircleV(bezierCurve[i], 5, PURPLE);
		}
		for (float i = 0.05; i < 1; i += 0.01)
		{
			//DrawCircleV(cMath::cubicBezier(bezierCurve[0], bezierCurve[1], bezierCurve[2], i), 5, GREEN);
			DrawCircleV(cMath::quadraticBezier(bezierCurve[0], bezierCurve[1], bezierCurve[2], bezierCurve[3], i), 3, GREEN);
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