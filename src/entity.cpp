#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

using namespace std;

Entity::Entity(Vector2f p_pos, vector<SDL_Texture*> p_textures)
:pos(p_pos), textures(p_textures) 
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	SDL_QueryTexture(p_textures[0], NULL, NULL, &currentFrame.w, &currentFrame.h);
}