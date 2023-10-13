
#include <raylib.h>
#include <iostream>

int main()
{
	InitWindow(800, 800, "raylib window");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("This is a test window :D", 300, 350, 20, RAYWHITE);
		EndDrawing();

	}
}
