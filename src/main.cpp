
#include <raylib.h>
#include <iostream>

int main()
{
	InitWindow(800, 800, "raylib window");
	SetTargetFPS(60);
	float last_tick = 0.0;
	int total_ticks = 0;
	while (!WindowShouldClose()) {
		BeginDrawing();
		
		last_tick += GetFrameTime();
		
		//20 TPS based updates
		if (last_tick > 0.05) {
			last_tick = 0;
			total_ticks++;
			ClearBackground(BLACK);
			DrawText(TextFormat("%d", total_ticks), 300, 350, 20, RAYWHITE);
		}
		EndDrawing();
	}
}
