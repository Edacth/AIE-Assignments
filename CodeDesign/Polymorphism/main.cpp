#include "raylib.h"
#include "Barbarian.h"
#include "Mage.h"
#include "button.h"
#include "Enemy.h"
#include "EvilEnt.h"
#include <vector>
#include <iterator>

void main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;


	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	const int NUM_OF_BUTTONS = 4;

	int gameState = 1;
	Button menuButtons[NUM_OF_BUTTONS] = { { "red_button", 3, 200, 200 }, { "green_button", 3, 400, 200 }, { "green_button", 3, 700, 100 }, { "red_button", 3, 700, 200 } };
	Texture2D* menuSprites[2] = { &LoadTexture("resources//barbarian.png"), &LoadTexture("resources//wizard.png") };
	Barbarian barbarian = { "resources//barbarian.png" };
	Mage mage = { "resources//Wizard.png" };
	EvilEnt evilEnt = { "resources//evil_ent.png", 100, 200};
	Player *player1 = NULL;
	int enemySpawnCount = 1;
	std::vector <Enemy*> enemies;
	

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if (gameState == 1)
		{
			// Update
			//----------------------------------------------------------------------------------
			if (menuButtons[0].Update() == 3)
			{
				
				player1 = &barbarian;
				gameState = 2;
				for (int i = 0; i < enemySpawnCount; i++)
				{
					EvilEnt * newEnt = new EvilEnt(evilEnt);

					enemies.push_back(newEnt);
				}
				for (std::vector<Enemy*>::iterator eneIte = enemies.begin(); eneIte != enemies.end(); eneIte++)
				{
					(*eneIte)->position = { (float)GetRandomValue(0, screenWidth), (float)GetRandomValue(0, screenHeight) };
				}
				
			}
			if (menuButtons[1].Update() == 3)
			{

				player1 = &mage;
				gameState = 2;
				for (int i = 0; i < enemySpawnCount; i++)
				{
					EvilEnt * newEnt = new EvilEnt(evilEnt);

					enemies.push_back(newEnt);
				}
				for (std::vector<Enemy*>::iterator eneIte = enemies.begin(); eneIte != enemies.end(); eneIte++)
				{
					(*eneIte)->position = { (float)GetRandomValue(0, screenWidth), (float)GetRandomValue(0, screenHeight) };
				}
			}
			if (menuButtons[2].Update() == 3)
			{
				enemySpawnCount++;
				
			}
			if (menuButtons[3].Update() == 3)
			{
				if (enemySpawnCount > 0)
				{
					enemySpawnCount--;
				}
				
				
			}

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
			DrawTexture(*menuSprites[0], 210, 170, WHITE);
			DrawTexture(*menuSprites[1], 410, 170, WHITE);
			for (int i = 0; i < NUM_OF_BUTTONS; i++)
			{
				menuButtons[i].Draw();
			}
			ClearBackground(RAYWHITE);
			DrawText("Choose your fighter", screenWidth/2, 10, 20, BLACK);
			DrawText(std::to_string(enemySpawnCount).c_str(), 700, 150, 20, BLACK);
			EndDrawing();
		}
		if (gameState == 2)
		{
			// Update
			//----------------------------------------------------------------------------------
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				player1->destination = GetMousePosition();
			}
			player1->moveTo();
			for (std::vector<Enemy*>::iterator eneIte = enemies.begin(); eneIte != enemies.end(); eneIte++)
			{
				(*eneIte)->Update(player1->position);
			}
			
			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(RAYWHITE);
			player1->Draw();
			DrawText(std::to_string(player1->position.x).c_str(), 10, 10, 10, BLACK);

			for (std::vector<Enemy*>::iterator eneIte = enemies.begin(); eneIte != enemies.end(); eneIte++)
			{
				(*eneIte)->Draw();
			}
			EndDrawing();
			//----------------------------------------------------------------------------------
		}
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

}

void startGame()
{

}