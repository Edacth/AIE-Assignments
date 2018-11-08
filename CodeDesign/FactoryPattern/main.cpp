//main.cpp
#include<iostream>
#include <string>
#include <vector>

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
	std::vector<FallingObject> objectList;
	
	//FallingObject* b;
	//b = FallingFactory::GetInstance().Create({ 100, 200 });
	

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_R))
		{
			objectList.push_back(*FallingFactory::GetInstance().Create({ (float)GetRandomValue(0, screenWidth), 0 }));
		}

		for (size_t i = 0; i < objectList.size(); i++)
		{
			objectList[i].Update();
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		//b->Draw();
		for (size_t i = 0; i < objectList.size(); i++)
		{
			objectList[i].Draw();
		}
		

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