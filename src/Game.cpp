#include "Game.h"
#include <raylib.h>
#include <raygui.h>

Game::Game() {
	this->score = 0;
	this->lives = 3;
	this->time = 0;
	this->time_interval = 0;
	this->spawn_interval = 0;
	this->x_pos = NULL;
	this->y_pos = NULL;
	this->heart_full = LoadTexture("assets/images/heart_full_64x64.png");
	this->heart_empty = LoadTexture("assets/images/heart_empty_64x64.png");
}

void Game::PollMouse() {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		this->x_pos = GetMouseX();
		this->y_pos = GetMouseY();
	}

}

std::vector<Entity> Game::GetEntities() {
	return this->entities;
}

void Game::Update() {
	
	PollMouse();

	for (auto i = 0; i < this->entities.size(); i++) {
		if (this->entities[i].GetDefeated()) {
			this->score += entities[i].GetValue();
			this->entities.erase(this->entities.begin() + i);
		}

		else if (this->entities[i].GetExpired()) {
			this->lives--;
			this->entities.erase(this->entities.begin() + i);
		}
		else {
			this->entities[i].Update(this->x_pos, this->y_pos);
		}
	}

	this->x_pos = this->y_pos = NULL;
	this->time_interval += GetFrameTime();

	spawnEntity();
	
}

void Game::spawnEntity() {
	if (this->entities.size() < this->MAX_ENTITIES && 
		this->time_interval > this->spawn_interval) {
		this->entities.push_back(Entity());
		this->spawn_interval = time_interval + 0.5;
		
	}
}

void Game::Draw() {

	ClearBackground(RAYWHITE);
	DrawRectangle(0, 0, 1000, 100, { 200, 200, 200, 160 });
	
	for (int i = 0; i < 3; i++) {
		if (this->lives > i) {
			DrawTexture(this->heart_full, 500 + 100 * i, 13, WHITE);
		}
		
		else {
			DrawTexture(this->heart_empty, 500 + 100 * i, 13, WHITE);
		}
	}

	DrawText("Score:", 50, 35, 30, BLACK);
	DrawText(TextFormat("%d", this->score), 180, 35, 30, BLACK);

	for (auto i : this->entities) {
		i.Draw();
	}
}

