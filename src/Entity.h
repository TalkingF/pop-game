#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

class Entity {
	int value;
	float size;
	int x_pos;
	int y_pos;
	bool mark_for_delete = false;
	Color color;


public:
	Entity();
	~Entity();
	void Update(int &x, int &y);
	void Draw();
	bool GetMarkForDelete();
	int GetValue();



};

#endif // !ENTITY_H
