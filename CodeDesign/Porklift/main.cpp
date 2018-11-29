#include "raylib.h"
#include "button.h"
#include "stateMachine.h"
#include "GameObject.h"
#include "player.h"
#include "tile.h"
#include "crate.h"
#include <vector>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (1600);
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	Texture2D gameObjectTextures[3] = {
		{LoadTexture("resources//forklift.png")},
		{LoadTexture("resources//forklift_arm.png")},
		{ LoadTexture("resources//crate.png")}
	};
	Texture2D tileTextures[1] = {
		{LoadTexture("resources//floor_1.png")}
	};
	Button mainMenuButtons[2] = {
		{"blue_button", 3, screenWidth / 2 - 100, screenHeight / 2 - 30},
		{"green_button", 3, screenWidth - 60, screenHeight - 60}
	};
	Button optionMenuButtons[] = {
		{ "green_button", 3, screenWidth - 60, screenHeight - 60 }
	};
	std::vector<GameObject*> gameObjects;
	std::vector<tile*> tileVector;
	tile tiles[10] = { 
		{tileTextures[0], {0,600}},
		{tileTextures[0], {128,600}},
		{tileTextures[0], {256,600}},
		{tileTextures[0], {384,600}},
		{tileTextures[0], {512,600}},
		{tileTextures[0], {640,600}},
		{tileTextures[0], {0,472}},
		{tileTextures[0], {640,472}},
		{tileTextures[0], {384,440}},
		};
	player basePlayer = {gameObjectTextures[0], gameObjectTextures[1], {200 ,200}, &tileVector, &gameObjects };
	player* basePlayerPtr = &basePlayer;
	crate crates[10] = {
		{ gameObjectTextures[2], {300, 10}, &tileVector, &gameObjects },
		{ gameObjectTextures[2], {400, 10}, &tileVector, &gameObjects }
	};
	//crate* baseCratePtr = &baseCrate;
	tile baseTile = { tileTextures[0], {0,600} };
	tile* baseTilePtr = &baseTile;
	gameObjects.push_back(basePlayerPtr);
	gameObjects.push_back(&crates[0]);
	gameObjects.push_back(&crates[1]);
	
		//tile* newTile = new tile(tileTextures[0], { 0,600 });
		tileVector.push_back(&tiles[0]);
		tileVector.push_back(&tiles[1]);
		tileVector.push_back(&tiles[2]);
		tileVector.push_back(&tiles[3]);
		tileVector.push_back(&tiles[4]);
		tileVector.push_back(&tiles[5]);
		tileVector.push_back(&tiles[6]);
		tileVector.push_back(&tiles[7]);
		//tileVector.push_back(&tiles[7]);

		
	
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
			for (size_t i = 0; i < tileVector.size(); i++)
			{
				tileVector[i]->draw();
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