#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Math.hpp"

using namespace std;

class Entity {
public:
	Entity(Vector2f p_pos, vector<SDL_Texture*> p_textures);
	Vector2f& getPos() { return pos; }
	SDL_Texture* getTexture() { return textures[0]; }
	SDL_Rect getCurrentFrame() { return currentFrame; }
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	vector<SDL_Texture*> textures;
};