#include "Entity.h"
#include <stdlib.h>     
#include <time.h> 

Entity::Entity() {
	srand(time(NULL));
	int random = rand() % 11; //rand = (0-11)

	switch (random)
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
	}

	random = rand() % 20 + 20;
	this->size = random;
	this->score = 600 - 5 * random; //max score = (500-400);
}