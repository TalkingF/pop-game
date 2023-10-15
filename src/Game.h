#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include <vector>

class Game {
	int score;
	int lives;
	float time; //used for counting down or up in time attacks and survival
	float time_interval; //used for spawning entities
	float spawn_interval;
	int x_pos;
	int y_pos;
	const int MAX_ENTITIES = 15;
	
	std::vector<Entity> entities;

	void PollMouse();
	void spawnEntity();


public:
	Game();
	std::vector<Entity> GetEntities();
	
	void Update();
	void Draw();
	
	
};
#endif // !GAME_H

