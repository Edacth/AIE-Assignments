//main.cpp
#include<iostream>
#include <string>
#include <vector>

#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"
#include "FallingFactory.h"
#include "tObjectPool.h"
/*
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
		if (IsKeyPressed(KEY_R))
		{
			//objectList.push_back(*FallingFactory::GetInstance().Create("rock"));
			//objectList.push_back(*FallingFactory::GetInstance().Create("debris"));

		}

		if (IsKeyPressed(KEY_T))
		{
			FallingObject b = *objectList.back().Clone();
			objectList.push_back(b);
			objectList.back().pos.x += 30;
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

	
	IBox* p = NULL;
	p = Factory::GetInstance().Create("Red");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	p = Factory::GetInstance().Create("Blue");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	
	return 1;
}
*/
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);
	//std::vector<FallingObject> objectList;
	const int poolSize = 5;
	tObjectPool<FallingObject> myPool(poolSize);
	FallingObject* b = nullptr;
	//b = FallingFactory::GetInstance().Create({ 100, 200 });


	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyPressed(KEY_R))
		{
			//objectList.push_back(*FallingFactory::GetInstance().Create("rock"));
			//objectList.push_back(*FallingFactory::GetInstance().Create("debris"));
			myPool.retrieve();

		}
		if (IsKeyPressed(KEY_T))
		{
			int rand;
			do
			{
				rand = GetRandomValue(0, poolSize-1);
				
			} while (myPool.getFree()[rand] != false && myPool.freeCount() != 3);
			myPool.recycle(&myPool.pool[rand]);
		}

		myPool.updateAge();
		for (size_t i = 0; i < myPool.getCapacity(); i++)
		{
			if (myPool.getFree()[i] == false)
			{
				myPool.pool[i].Update();
				if (myPool.pool[i].pos.y > screenHeight)
				{
					myPool.recycle(&myPool.pool[i]);
				}
			}

			
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		//b->Draw();
		for (size_t i = 0; i < myPool.getCapacity(); i++)
		{
			if (myPool.getFree()[i] == false)
			{
				myPool.pool[i].Draw();
			}
		}
		DrawText((std::to_string(myPool.freeCount())).c_str(), 10, 10, 30, BLACK);

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