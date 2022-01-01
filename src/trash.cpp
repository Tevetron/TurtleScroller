#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Trash.hpp"

using namespace std;

Trash::Trash(Vector2f p_pos, vector<SDL_Texture*> p_textures)
:Entity{ p_pos, p_textures } {}

void Trash::update() {
	getPos().x -=5;
}