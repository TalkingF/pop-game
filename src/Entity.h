#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

class Entity {
	int score;
	int size;
	Color color;


public:
	Entity();
	void Process();


};

#endif // !ENTITY_H
