#include "Game.h"
#include <raylib.h>

Game::Game() {
	this->score = 0;
	this->lives = 3;
	this->time = 0;
	this->time_interval = 0;
	this->spawn_interval = 0;
	this->x_pos = NULL;
	this->y_pos = NULL;
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
		if (this->entities[i].GetMarkForDelete()) {
			this->score += entities[i].GetValue();
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
	DrawText(TextFormat("%d", score), 300, 350, 20, BLACK);
	DrawText(TextFormat("%d", this->entities.size()), 500, 350, 20, BLACK);

	for (auto i : this->entities) {
		i.Draw();
	}
}

