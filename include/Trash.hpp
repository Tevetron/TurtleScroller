#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Entity.hpp"

using namespace std;

class Trash : public Entity {
public:
	Trash(Vector2f p_pos, vector<SDL_Texture*> p_textures);
	void update();
private:
	float velocityX, velocityY;
	bool onGround;
};