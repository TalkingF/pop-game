
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <iostream>
#include "Entity.h"
#include "Game.h"


int main()
{
	//init
	InitWindow(1000, 1000, "raylib window");
	SetTargetFPS(60);
	srand(time(NULL));
	Game game;
	
	
	while (!WindowShouldClose()) {
		
		BeginDrawing();
		game.Update();
		game.Draw();
		EndDrawing();
		
	}
	CloseWindow();
}
