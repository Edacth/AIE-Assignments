#include "raylib.h"
#include "stateMachine.h"
#include "player.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = (800);
	int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	Texture oozeTexture = LoadTexture("resources//ooze.png");
	Texture skeletonTexture = LoadTexture("resources//skeleton.png");
	Player player;
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (stateMachine::getState() == MainMenu) //MAIN MENU
		{
			if (IsKeyDown(KEY_SPACE))
			{
				stateMachine::setState(1);
			}
		}
		if (stateMachine::getState() == PlayerSelect) //SELECTION MENU
		{
			if (IsKeyDown(KEY_A))
			{
				stateMachine::setState(2);
				player = { oozeTexture ,{ (float)screenWidth / 2, (float)screenHeight / 2 } };
			}
			if (IsKeyDown(KEY_D))
			{
				stateMachine::setState(2);
				player = { skeletonTexture, {(float)screenWidth / 2, (float)screenHeight / 2} };
			}
		}
		if (stateMachine::getState() == InGame) //GAMEPLAY
		{
			if (IsKeyPressed(KEY_R))
			{
				stateMachine::setState(3);
			}
			if (IsKeyDown(KEY_W))
			{
				player.position.y -= 2;
			}
			if (IsKeyDown(KEY_S))
			{
				player.position.y += 2;
			}
			if (IsKeyDown(KEY_A))
			{
				player.position.x -= 2;
			}
			if (IsKeyDown(KEY_D))
			{
				player.position.x += 2;
			}
		}
		if (stateMachine::getState() == GameOver) //DEATH SCREEN
		{
			if (IsKeyPressed(KEY_SPACE))
			{
				stateMachine::setState(1);
			}
		}
		
		
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		if (stateMachine::getState() == MainMenu)
		{
			DrawText("MAIN MENU", screenWidth / 2 - 100, 10, 30, BLACK);
			DrawText("Press the spacebar", screenWidth / 2 - 100, (screenHeight / 2) + 30, 20, BLACK);
		}
		if (stateMachine::getState() == PlayerSelect)
		{
			DrawText("CHOICE MENU", screenWidth / 2 - 100, 10, 30, BLACK);
			DrawTextureEx(oozeTexture, {250, (float)(screenHeight / 2) }, 0, 4.0, WHITE);
			DrawTextureEx(skeletonTexture, {450, (float)(screenHeight / 2) }, 0, 4.0, WHITE);
		}
		if (stateMachine::getState() == InGame)
		{
			DrawText("<GAMEPLAY>", screenWidth / 2 - 100, 10, 30, BLACK);
			DrawText("Press R to die.", screenWidth / 2 - 100, (screenHeight - 30), 20, BLACK);
			player.draw();
		}
		if (stateMachine::getState() == GameOver)
		{
			DrawText("YOU DIED.", screenWidth / 2 - 100, screenHeight / 2, 30, BLACK);
			DrawText("Press spacebar to continue.", screenWidth / 2 - 100, (screenHeight) - 30, 20, BLACK);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}