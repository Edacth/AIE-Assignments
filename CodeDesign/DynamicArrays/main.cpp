#include "tVector.h"
#include <iostream>
#include "raylib.h"
#include "Ninja.h"
#include "GameObject.h"
#include "tStack.h"
#include "projectile.h"
#include "tQueue.h"


int main()
{

	/*
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;
	

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	tVector<Ninja> array1;
	Ninja ninja1 = { 100, 100 };

	tStack<int> spellQueue;
	projectile baseProj;
	tVector<projectile> projectileArr;
	
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		if (IsKeyPressed(KEY_Q))
		{
			spellQueue.push(1);
		}
		if (IsKeyPressed(KEY_W))
		{
			spellQueue.push(2);
		}
		if (IsKeyPressed(KEY_E))
		{
			spellQueue.push(3);
		}
		if (IsKeyPressed(KEY_R))
		{
			spellQueue.push(4);
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			switch (spellQueue.top())
			{
			case 1:
				baseProj.color = BLUE;
				projectileArr.push_back(baseProj);
			spellQueue.pop();
				break;
			case 2:
				baseProj.color = RED;
				projectileArr.push_back(baseProj);
				spellQueue.pop();
				break;
			case 3:
				baseProj.color = GREEN;
				projectileArr.push_back(baseProj);
				spellQueue.pop();
				break;
			case 4:
				baseProj.color = YELLOW;
				projectileArr.push_back(baseProj);
				spellQueue.pop();
				break;
			default:
				break;
			}
			
		}

		for (size_t i = 0; i < projectileArr.used(); i++)
		{
			projectileArr[i].update();
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			//ninja1.position = { (float)GetRandomValue(0, 800), (float)GetRandomValue(0, 400) };
			//array1.push_back(ninja1);
		}
		
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		for (size_t i = 0; i < 5; i++)
		{
			//array1[i].render();
		}
		for (size_t i = 0; i < 5; i++)
		{
			switch (spellQueue.top())
			{
			case 1:
				DrawRectangle(10, 10, 30, 30, BLUE);
				break;
			case 2:
				DrawRectangle(10, 10, 30, 30, RED);
				break;
			case 3:
				DrawRectangle(10, 10, 30, 30, GREEN);
				break;
			case 4:
				DrawRectangle(10, 10, 30, 30, YELLOW);
				break;
			default:
				DrawRectangle(10, 10, 30, 30, GRAY);
				break;
			}
			
		}
		for (size_t i = 0; i < projectileArr.used(); i++)
		{
			projectileArr[i].draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------
	
	*/

	//std::cout << array1.empty() << std::endl;
	//array1.push_back(5);
	//std::cout << array1.empty() << std::endl;
	//

	//array1.push_back(30);
	//array1.push_back(500);
	////tVector<int> array2 = { array1 };
	//array1.print();
	//array1.clear();
	//array1.print();
	////std::cout << array1[0] << std::endl;
	////array2 = array1;
	////array2.print();

	//tStack<int> myStack;
	//std::cout << myStack.empty() << std::endl;
	//myStack.push(2);
	//std::cout << myStack.empty() << std::endl;
	
	tQueue<int> myQueue;
	myQueue.push(1);
	myQueue.push(3);
	myQueue.push(5);

	std::cout << myQueue.front() << std::endl;
	myQueue.pop();
	std::cout << myQueue.front() << std::endl;
	std::cout << myQueue.back() << std::endl;

	//std::cout << (myStack.top()) << std::endl;

	return 0;
}