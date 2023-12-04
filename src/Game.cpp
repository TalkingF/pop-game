#include "Game.h"
#include <raylib.h>
#include <raygui.h>
#include <iostream>

Game::Game() {
	this->score = 0;
	this->lives = 3;
	this->time = 0;
	this->spawn_interval = 0;
	this->immunity_interval = 0;
	this->x_pos = NULL;
	this->y_pos = NULL;
	this->heart_full = LoadTexture("../../../assets/images/heart_full_64x64.png");
	this->heart_empty = LoadTexture("../../../assets/images/heart_empty_64x64.png");
	this->exit_game = false;
	this->miss = false;
	this->sound_click = LoadSound("../../../assets/sounds/Mouse Hover Glass A.wav");
	this->sound_miss = LoadSound("../../../assets/sounds/Click Plastic.wav");
}

//gets mouse coords if mouse is clicked
void Game::PollMouse() {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		this->x_pos = GetMouseX();
		this->y_pos = GetMouseY();
	}

}

std::vector<std::shared_ptr<Entity>> Game::GetEntities() {
	return this->entities;
}

bool Game::GetExitGame() {
	return this->exit_game;
}

void Game::Update() {

	PollMouse();
	
	//end current game game
	if (this->lives < 1) {
		this->entities.clear();
	}

	//iterates over each entity
	else {
		bool empty_click = this->x_pos == NULL;
		for (auto i = 0; i < this->entities.size(); i++) {
			if (this->entities[i]->GetDefeated()) { //enemies clicked on
				this->score += entities[i]->GetValue();
				this->entities.erase(this->entities.begin() + i);
			}

			else if (this->entities[i]->GetExpired()) { //enemies expired
				this->lives--;
				this->entities.erase(this->entities.begin() + i);
			}
			else {
				this->entities[i]->Update(this->x_pos, this->y_pos); //update the rest
				if (this->x_pos == NULL && !empty_click) {
					PlaySound(this->sound_click);
				}
			}
		}

		//click was registered but didn't overlap with any circle
		if (this->x_pos != NULL && this->y_pos != NULL && time > immunity_interval) {
			PlaySound(this->sound_miss);
			this->miss = true;
			this->score -= 500;
			if (this->score < 0) this->score = 0;
			this->immunity_interval = time + 2.0;
			this->x_pos = this->y_pos = NULL;
	
		}

		
		this->time += GetFrameTime();
		
		spawnEntity();
	}
}

//checks if time has elapsed since last entity and that there is room
void Game::spawnEntity() {

	if (this->entities.size() < this->MAX_ENTITIES && 
		this->time > this->spawn_interval) {
		this->entities.emplace_back(std::make_shared<Entity>());
		this->spawn_interval = time + 0.5;
		
	}
}

//draws game to screen
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
			this->spawn_interval = 0;
			this->immunity_interval = 0;
			this->x_pos = NULL;
			this->y_pos = NULL;
			this->miss = false;
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

		if (this->miss) {
			DrawText("-500", 300, 35, 30, RED);
			if (time > immunity_interval) this->miss = false;
		}

		for (auto i = 0; i < entities.size(); i++) entities[i]->Draw();
	}
}

Game::~Game() {
	UnloadTexture(this->heart_full);
	UnloadTexture(this->heart_empty);
	UnloadSound(this->sound_click);
	UnloadSound(this->sound_miss);
}