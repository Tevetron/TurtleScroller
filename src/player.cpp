#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Player.hpp"

using namespace std;

Player::Player(Vector2f p_pos, vector<SDL_Texture*> p_textures)
:Entity{ p_pos, p_textures } {}

void Player::clamp() {
	if(getPos().y < 0)
		getPos().y = 0;
	if(getPos().y > 720 - 32)
		getPos().y = 720 - 32;
}

void Player::update() {
	getPos().x = 128;
	int mouseX = 0;
	int mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	getPos().y = mouseY - 54;
	clamp();
}