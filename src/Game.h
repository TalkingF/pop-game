#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include <vector>
#include <memory>

class Game {
	
	int score;
	int lives;
	float time;
	float spawn_interval;
	float immunity_interval;
	int x_pos;
	int y_pos;
	const int MAX_ENTITIES = 15;
	Texture heart_full;
	Texture heart_empty;
	bool exit_game;
	bool miss;
	Sound sound_click;
	Sound sound_miss;
	std::vector<std::shared_ptr<Entity>> entities;

	void PollMouse();
	void spawnEntity();


public:
	Game();
	~Game();
	std::vector<std::shared_ptr<Entity>> GetEntities();
	bool GetExitGame();
	void Update();
	void Draw();
};
#endif // !GAME_H

