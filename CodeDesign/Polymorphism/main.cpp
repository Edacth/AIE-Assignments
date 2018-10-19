#include "raylib.h"
#include "Barbarian.h"
#include "Mage.h"
#include "button.h"
#include "Enemy.h"
#include "EvilEnt.h"

void main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;


	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	int gameState = 1;
	Button barbButton = { "red_button", 3, 200, 200 };
	Button WizButton = { "green_button", 3, 400, 200 };
	Barbarian barbarian = { "resources//barbarian.png" };
	Mage Mage = { "resources//Wizard.png" };
	EvilEnt evilEnt = { "resources//evil_ent.png", 100, 200};
	Player *player1 = NULL;
	Enemy* enemies[10];
	enemies[0] = {&evilEnt};

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if (gameState == 1)
		{
			// Update
			//----------------------------------------------------------------------------------
			if (barbButton.Update() == 3)
			{
				
				player1 = &barbarian;
				gameState = 2;
			}
			if (WizButton.Update() == 3)
			{

				player1 = &Mage;
				gameState = 2;
			}

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
			barbButton.Draw();
			WizButton.Draw();
			ClearBackground(RAYWHITE);
			DrawText("Choose your fighter", screenWidth/2, 10, 20, BLACK);
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
			enemies[0]->Update(player1->position);
			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(RAYWHITE);
			player1->Draw();
			DrawText(std::to_string(player1->position.x).c_str(), 10, 10, 10, BLACK);

			enemies[0]->Draw();
			EndDrawing();
			//----------------------------------------------------------------------------------
		}
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

}