#include "Entity.h"

Entity::Entity(Sprite* spr, Point pos)
{
    en_sprite = spr;
    position = pos;
}

void Entity::Update()
{
}

void Entity::Draw(SDL_Renderer* renderer)
{
    en_sprite->renderAtScreenPos(renderer, position.x, position.y, 0, 0);
}

void Entity::SetPosition(Point pos)
{
    position = pos;
}

Point Entity::GetPosition()
{
    return position;
}
