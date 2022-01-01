#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Entity.hpp"

using namespace std;

class Player : public Entity {
public:
	Player(Vector2f p_pos, vector<SDL_Texture*> p_textures);
	void clamp();
	void update();
private:
	float velocityX, velocityY;
	bool onGround;
};