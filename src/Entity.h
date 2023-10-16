#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

class Entity {
	int value;
	float size;
	int x_pos;
	int y_pos;
	bool expired;
	bool defeated;
	Color color;
	


public:
	Entity();
	~Entity();
	void Update(int &x, int &y);
	void Draw();
	bool GetExpired();
	bool GetDefeated();
	int GetValue();



};

#endif // !ENTITY_H
