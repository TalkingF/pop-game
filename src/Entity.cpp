#include "Entity.h"
#include <stdlib.h>     
#include <time.h> 
#include <iostream>
#include <cmath>

Entity::Entity() {
	
	switch (rand() % 11)
	{
	case 0:
		this->color = RED;
		break;
	case 1:
		this->color = GREEN;
		break;
	case 2:
		this->color = BLUE;
		break;
	case 3: 
		this->color = YELLOW;
		break;
	case 4:
		this->color = ORANGE;
		break;
	case 5: 
		this->color = PURPLE;
		break;
	case 6: 
		this->color = PINK;
		break;
	case 7:
		this->color = MAGENTA;
		break;
	case 8:
		this->color = GOLD;
		break;
	case 9:
		this->color = MAROON;
		break;
	case 10:
		this->color = SKYBLUE;
		break;
	case 11:
		this->color = LIME;
		break;
	default:
		this->color = BLANK;
		std::cerr << "Colour out of bounds";
	}

	float rand_size= rand() % 20 + 20.0;
	this->size = rand_size;
	this->score = 600 - 5 * rand_size; //max score = (500-400)
	this->x_pos = rand() % 600 + 100; // ensures entities dont expand past edge
	this->y_pos = rand() % 600 + 100;
	DrawCircle(this->x_pos, this->y_pos , this->size, this->color);
}

//TODO: delete entity with larger score
void Entity::Update(int &x, int &y) {

	//check collision
	if (x != NULL || y != NULL) {
		if (sqrt(pow(x - this->x_pos, 2) + pow(y - this->y_pos, 2)) < this->size) {
			this->mark_for_delete = true;
			x = y = NULL; //allows only once entity to be destroyed per click
		}
	}
	
	//change size
	this->size *= 1.02;

	//change score
	this->score -= 10;

	//check if too big
	if (this->score < 0) {
		this->score = 0;
		this->mark_for_delete = true;
	}

}

void Entity::Draw() {
	DrawCircle(this->x_pos, this->y_pos, this->size, this->color);

}

bool Entity::getMarkForDelete() {
	return this->mark_for_delete;
}

int Entity::getScore() {
	return this->score;
}

Entity::~Entity() {
	

}
