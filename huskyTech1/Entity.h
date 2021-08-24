#pragma once
#include <SDL.h>
#include "ht_types.h"
#include "Sprite.h"

class Entity
{
	
public:
	Entity(Sprite* spr, Point pos = { 0, 0 });

	void Update();

	void Draw(SDL_Renderer* renderer);

	void SetPosition(Point pos);

	Point GetPosition();

	Point velocity = { 0, 0 };

private:
	Point position;
	Sprite* en_sprite;
};

