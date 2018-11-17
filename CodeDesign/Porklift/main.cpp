#include "raylib.h"
#include "button.h"
#include "stateMachine.h"
#include "GameObject.h"
#include "player.h"
#include <vector>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	Texture2D gameObjectTextures[1] = {
		{LoadTexture("resources//barbarian.png")}
	};
	Button mainMenuButtons[2] = {
		{"blue_button", 3, screenWidth / 2 - 100, screenHeight / 2 - 30},
		{"green_button", 3, screenWidth - 60, screenHeight - 60}
	};
	Button optionMenuButtons[] = {
		{ "green_button", 3, screenWidth - 60, screenHeight - 60 }
	};
	std::vector<GameObject*> gameObjects;
	player basePlayer = { gameObjectTextures[0], {100 ,100} };
	player* basePlayerPtr = &basePlayer;
	gameObjects.push_back(basePlayerPtr);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		switch (stateMachine::getState())
		{
		case MainMenu:
		{
			// Update
			//----------------------------------------------------------------------------------
			for (size_t i = 0; i < 2; i++) //simulate buttons
			{
				mainMenuButtons[i].update();
			}

			if (mainMenuButtons[0].getState() == 3) //START BUTTON
			{
				stateMachine::setState(InGame);
			}

			if (mainMenuButtons[1].getState() == 3) //OPTIONS BUTTON
			{
				stateMachine::setState(OptionsMenu);
			}

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawText("MAIN MENU", screenWidth / 2 - 100, 10, 30, BLACK);
			//DrawText((std::to_string(mainMenuButtons[1].getState())).c_str(), 10, 10, 30, BLACK);

			for (size_t i = 0; i < 2; i++) //Draw buttons
			{
				mainMenuButtons[i].draw();
			}

			
			DrawText("Start", screenWidth / 2 - 30, (screenHeight / 2) - 60, 20, BLACK);
			DrawText("Options", screenWidth - 60, screenHeight - 80, 15, BLACK);
			

			EndDrawing();
			//----------------------------------------------------------------------------------
			break;
		}
		case OptionsMenu:
		{
			// Update
			//----------------------------------------------------------------------------------
			for (size_t i = 0; i < 1; i++)
			{
				optionMenuButtons[i].update();
			}

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawText("OPTIONS MENU", screenWidth / 2 - 100, 10, 30, BLACK);

			for (size_t i = 0; i < 1; i++) //Draw buttons
			{
				optionMenuButtons[i].draw();
			}


			DrawText("Your only option is to Porklift", screenWidth / 2 - 300, (screenHeight / 2) - 60, 35, BLACK);
			DrawText("Main Menu", screenWidth - 70, screenHeight - 80, 15, BLACK);

			if (optionMenuButtons[0].getState() == 3)
			{
				stateMachine::setState(MainMenu);
			}

			EndDrawing();
			//----------------------------------------------------------------------------------
			break;
		}
		case InGame:
		{
			// Update
			//----------------------------------------------------------------------------------
			for (size_t i = 0; i < gameObjects.size(); i++)
			{
				gameObjects[i]->update();
			}

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
			ClearBackground(RAYWHITE);

			for (size_t i = 0; i < gameObjects.size(); i++)
			{
				gameObjects[i]->draw();
			}

			EndDrawing();
			//----------------------------------------------------------------------------------
			break;
		}
		default:
			break;
		}
		
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//-----------------------
	return 0;
}