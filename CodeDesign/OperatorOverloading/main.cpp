#include <iostream>
#include "myHero.h"
#include "raylib.h"
#include <string>
#include "MyColor.h"
#include "tile.h"
#include <sstream> 
#include <fstream>



int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int MAP_HEIGHT = 16;
	const int MAP_WIDTH = 16;
	int screenWidth = (MAP_WIDTH * 64) +128;
	int screenHeight = MAP_HEIGHT * 64;
	Vector2 selectedTile = {0,0};
	Vector2 mousePos;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Tile* copiedTile;

	SetTargetFPS(60);

	
	Tile tilemap[MAP_WIDTH][MAP_HEIGHT];
	Tile masterTile = { };

	std::fstream file;
	std::string filePath = "resources//tileMapBig.txt";
	char buffer;
	
	
	

	file.open(filePath, std::ios::in);
	//while (file.get(buffer))  // iterates until error or EOF
	//{
	//	// print the line after it is buffered
	//	
	//	std::cout << buffer << std::endl;
	//}
	

	
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			char buffer;
			std::string fileName;

			file.get(buffer);
			switch (buffer)
			{
			case 'x':
				fileName = "mapTile_017.png";
				break;
			case 'o':
				fileName = "mapTile_188.png";
				break;
			case 'g':
				fileName = "mapTile_022.png";
				break;
			case 'm':
				fileName = "mapTile_027.png";
				break;
			default:
				i--;
				break;
			}
			tilemap[i][j] = { fileName };
			if (j >= MAP_WIDTH - 1)
			{
				file.get(buffer);
			}
		}
	}
	file.close();

	/*MyHero doomGuy;
	Potion greenPotion;
	Potion redPotion = { -10, 1.0};
	std::cout << doomGuy.hitPoints << std::endl;
	std::cout << greenPotion.HPModifier * greenPotion.quality << std::endl;

	MyColor burple = {40, 112, 226, 300};*/

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		mousePos = GetMousePosition();
		selectedTile.x = ( (int)mousePos.x / 64);
		selectedTile.y = ( (int)mousePos.y / 64);
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && mousePos.x < MAP_WIDTH * 64)
		{
			//tilemap[(int)selectedTile.y][(int)selectedTile.x].applyTexture(copiedTile);
			//if (tilemap[(int)selectedTile.y][(int)selectedTile.x] != *copiedTile)
			{
				tilemap[(int)selectedTile.y][(int)selectedTile.x] = *copiedTile ;
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			copiedTile = &tilemap[(int)selectedTile.y][(int)selectedTile.x];
		}

		if (IsKeyPressed(KEY_E))
		{
			std::fstream fileOut;
			fileOut.open(filePath, std::ios::out);
			for (int i = 0; i < MAP_WIDTH; i++)
			{
				for (int j = 0; j < MAP_HEIGHT; j++)
				{
					char buffer;
					std::string fileName;

					
					if (*tilemap[i][j].imageFilename == "mapTile_017.png")
					{
						buffer = 'x';
					}
					else if (*tilemap[i][j].imageFilename == "mapTile_188.png")
					{
						buffer = 'o';
					}
					else if (*tilemap[i][j].imageFilename == "mapTile_022.png")
					{
						buffer = 'g';
					}
					else if (*tilemap[i][j].imageFilename == "mapTile_027.png")
					{
						buffer = 'm';
					}
					fileOut << buffer;
					if (j >= MAP_WIDTH - 1)
					{
						fileOut << '\n';
					}
				}
			}
			fileOut.close();
		}
		//----------------------------------------------------------------------------------
		/*if (IsKeyPressed(KEY_Q))
		{
			doomGuy += greenPotion;
		}
		if (IsKeyPressed(KEY_E))
		{
			doomGuy += redPotion;
		}*/
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		/*DrawText( (std::to_string(doomGuy.hitPoints).c_str()), 30, 30, 10, BLACK);
		doomGuy.draw();

		DrawRectangle(300, 200, 20, 20, burple.convert() );*/
		for (int i = 0; i < MAP_WIDTH; i++)
		{
			for (int j = 0; j < MAP_HEIGHT; j++)
			{
				DrawTexture(*tilemap[i][j].Background, (j * 64), ( i * 64), WHITE);

			}
		}
		//DrawText(std::to_string(mousePos.x).c_str(), 10, 10, 10, BLACK);
		
		DrawRectangle(MAP_WIDTH * 64, 0, (MAP_WIDTH * 64), (MAP_HEIGHT * 64), GRAY);
		DrawText("Sidebar", MAP_WIDTH * 64, 10, 20, BLACK);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}