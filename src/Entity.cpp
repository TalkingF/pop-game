#include "Entity.h"
#include <stdlib.h>     
#include <time.h> 
#include <iostream>
#include <cmath>

Entity::Entity() {
	this->expired = false;
	this->defeated = false;
	
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
	this->value = 600 - 5 * rand_size; //max value = (500-400)
	this->x_pos = rand() % 800 + 100; // ensures entities dont expand past edge
	this->y_pos = rand() % 700 + 200;
	DrawCircle(this->x_pos, this->y_pos , this->size, this->color);
}

void Entity::Update(int &x, int &y) {

	//check collision
	if (x != NULL || y != NULL) {
		if (sqrt(pow(x - this->x_pos, 2) + pow(y - this->y_pos, 2)) < this->size) {
			this->defeated = true;
			x = y = NULL; //allows only once entity to be destroyed per click
		}
	}
	
	//change size
	this->size *= 1.008;

	//change value
	this->value -= 2;

	//check if too big
	if (this->value < 0 || this->size > 100) {
		this->value = 0;
		this->expired = true;
	}
}

void Entity::Draw() {
	DrawCircle(this->x_pos, this->y_pos, this->size, this->color);

}

bool Entity::GetExpired() {
	return this->expired;
}

bool Entity::GetDefeated() {
	return this->defeated;
}

int Entity::GetValue() {
	return this->value;
}

