#include "raylib.h"
#include "stateMachine.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include <vector>

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
	Texture knightTexture = LoadTexture("resources//knight.png");
	Texture boneTexture = LoadTexture("resources//bone.png");
	Player player;
	std::vector<Enemy> enemyArr;
	std::vector<Projectile> projectileArr;
	Enemy baseEnemy;
	Projectile baseProjectile;
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
			if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D))
			{
				if (IsKeyDown(KEY_A))
				{
					player = { oozeTexture ,{ (float)screenWidth / 2, (float)screenHeight / 2 } };
				}
				else if (IsKeyDown(KEY_D))
				{
					player = { skeletonTexture ,{ (float)screenWidth / 2, (float)screenHeight / 2 } };
				}
				stateMachine::setState(2);
				enemyArr.push_back(baseEnemy = { knightTexture, {0, 0} });
				enemyArr.push_back(baseEnemy = { knightTexture, {500, 0} });
				for (size_t i = 0; i < enemyArr.size(); i++)
				{
					enemyArr[i].setTarget(&player);
				}
			}
			
		}
		if (stateMachine::getState() == InGame) //INGAME
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
			for (size_t i = 0; i < enemyArr.size(); i++)
			{
				enemyArr[i].update();
			}
			for (size_t i = 0; i < projectileArr.size(); i++)
			{
				projectileArr[i].update();
			}
			if (IsKeyPressed(KEY_RIGHT))
			{
				projectileArr.push_back(baseProjectile = { boneTexture, player.position, {1, 0} });
			}
			if (IsKeyPressed(KEY_LEFT))
			{
				projectileArr.push_back(baseProjectile = { boneTexture, player.position,{ -1, 0 } });
			}
			if (IsKeyPressed(KEY_UP))
			{
				projectileArr.push_back(baseProjectile = { boneTexture, player.position,{ 0, -1 } });
			}
			if (IsKeyPressed(KEY_DOWN))
			{
				projectileArr.push_back(baseProjectile = { boneTexture, player.position,{ 0, 1 } });
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
			for (size_t i = 0; i < enemyArr.size(); i++)
			{
				enemyArr[i].draw();
			}
			for (size_t i = 0; i < projectileArr.size(); i++)
			{
				projectileArr[i].draw();
			}
			
		}
		if (stateMachine::getState() == GameOver)
		{
			DrawText("YOU DIED.", screenWidth / 2 - 100, screenHeight / 2, 30, BLACK);
			DrawText("Press spacebar to continue.", screenWidth / 2 - 100, (screenHeight) - 30, 20, BLACK);
			for (size_t i = 0; i < enemyArr.size(); i++)
			{
				enemyArr.pop_back();
			}
			for (size_t i = 0; i < projectileArr.size(); i++)
			{
				projectileArr.pop_back();
			}
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