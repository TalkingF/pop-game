#include "Game.h"
#include <raylib.h>
#include <raygui.h>
#include <iostream>

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
	this->exit_game = false;
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

bool Game::GetExitGame() {
	return this->exit_game;
}

void Game::Update() {

	PollMouse();

	if (this->lives < 1) {
		this->entities.clear();
	}

	else {
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
		this->time += GetFrameTime();

		spawnEntity();
	}
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

	if (this->lives < 1) {
		DrawRectangle(0, 0, 1000, 1000, { 96, 96, 96, 77 });
		DrawRectangleRounded({ 200, 200, 600, 600 }, 0.1, 10, RAYWHITE);
		DrawText("GAME OVER", 350, 250, 50, BLACK);
		DrawText("Score:", 250, 350, 30, BLACK);
		DrawText(TextFormat("%d", this->score), 370, 350, 30, BLACK);
		DrawText("Time Alive:", 250, 450, 30, BLACK);
		DrawText(TextFormat("%.2f", this->time), 420, 450, 30, BLACK);
		
		if (GuiButton({ 340, 500, 140, 80 }, "Play Again")) {
			this->score = 0;
			this->lives = 3;
			this->time = 0;
			this->time_interval = 0;
			this->spawn_interval = 0;
			this->x_pos = NULL;
			this->y_pos = NULL;
		}


		if (GuiButton({ 510, 500, 140, 80 }, "Quit")) this->exit_game = true;
	}

	else {

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
	
}

