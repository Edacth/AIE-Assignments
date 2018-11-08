//main.cpp
#include<iostream>
#include <string>

#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"
#include "FallingFactory.h"

int main() 
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		SimpleSprite b;
		b = FallingFactory::GetInstance().Create();
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//-----------------------

	/*
	IBox* p = NULL;
	p = Factory::GetInstance().Create("Red");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	p = Factory::GetInstance().Create("Blue");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	*/
	return 1;
}