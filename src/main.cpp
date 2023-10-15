﻿
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <iostream>
#include "Entity.h"
#include "Game.h"


int main()
{
	//init
	//setting dir to root
	for (int i = 0; i < 3; i++) {
		ChangeDirectory("..");
	}

	
	
	InitWindow(1000, 1000, "raylib window");
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
