//main.cpp
#include <iostream>
#include <vector>
#include "myStatis.h"
#include "raylib.h"
#include "dialFace.h"
#include <string>

/*
int myStasis::petShop = 0;//not assigning petShop from outside the class results in errors.
int main() {
	myStasis test1 = { "Glow Cloud" };
	myStasis test2 = { "Dana Cardina" };
	test1.petShopBoys();//1
	test1.petShopBoys();//2
	test1.petShopBoys();//3
	test1.petShopBoys();//4
	test2.petShopBoys();//5
	test2.petShopBoys();//6
	myStasis::petShopBoys();//7
	myStasis::petShopBoys();//8
	myStasis::petShopBoys();//9

	return 0;
}*/

int main() 
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;

	dialFace dial1 = {300, 300, 80, 0.01f};
	dialFace dial2 = { 200, 200, 30, 0.1f};
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
			// Update
			//----------------------------------------------------------------------------------
			dial1.tick();
			dial2.tick();

			dial2.position.x = dial1.endingPoint.x;
			dial2.position.y = dial1.endingPoint.y;
			
			//----------------------------------------------------------------------------------
			

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
			
			ClearBackground(SKYBLUE);
			dial1.drawFace();
			dial2.drawFace();
			//DrawText(std::to_string(currentAngle).c_str(), 10, 10, 10, BLACK);
			EndDrawing();
			
		
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

}