
#include <raylib.h>
#include <iostream>
#include <vector>
#include "Entity.h"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>


int main()
{
	//init
	int score = 0;
	InitWindow(1000, 1000, "raylib window");
	SetTargetFPS(60);
	float last_tick = 0.0;
	int total_ticks = 0;
	std::vector<Entity> entities;
	int x = NULL;
	int y = NULL;
	srand(time(NULL));
	
	while (!WindowShouldClose()) {
		
		BeginDrawing();
		//poll mouse input
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			x = GetMouseX();
			y = GetMouseY();
		}
		
		
		//20 TPS based updates
		last_tick += GetFrameTime();
		if (last_tick > 0.05) {
			last_tick = 0;
			total_ticks++;

			//update entities
			for (auto i = 0; i < entities.size(); i++) {
				//cleans entities ready for deletion
				if (entities[i].getMarkForDelete()) {
					score += entities[i].getScore();
					entities.erase(entities.begin() + i);
				}
				else {
					entities[i].Update(x, y);
				}
				
			}

			//attempt to spawn entity every 20 ticks
			if (total_ticks % 15 == 0) {

				if (entities.size() < 16) {
					
					entities.push_back(Entity());
				}
			}
			
			//debug info
			ClearBackground(RAYWHITE);
			DrawText(TextFormat("%d", score), 300, 350, 20, BLACK);
			DrawText(TextFormat("%d", entities.size()), 500, 350, 20, BLACK);

			//draw entities 
			for (auto i : entities) {
				i.Draw();
			}
			x = y = NULL;
		}
		EndDrawing();
		
	}
	CloseWindow();
}
