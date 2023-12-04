
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <iostream>
#include "Entity.h"
#include "Game.h"


int main()
{
	InitWindow(1000, 1000, "pop!");
	InitAudioDevice();
	SetTargetFPS(60);
	srand(time(NULL));
	Game game;

	
	
	while (!game.GetExitGame() && !WindowShouldClose()) {
		
		BeginDrawing();
		game.Update();
		game.Draw();
		EndDrawing();
		
	}
	CloseWindow();
}
