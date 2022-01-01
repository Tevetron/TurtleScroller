#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Player.hpp"
#include "Trash.hpp"

using namespace std;

int main(int argc, char* args[]) {
	
	RenderWindow window("TurtScroll v1.0", 1280, 720);
	vector<SDL_Texture*> playerTextures;
	vector<SDL_Texture*> trashTextures;
	playerTextures.push_back(window.loadTexture("res/gfx/turtole.png"));
	trashTextures.push_back(window.loadTexture("res/gfx/bag.png"));

	Player player(Vector2f(0, 0), playerTextures);
	Trash trash(Vector2f(1280 - 50, 720 - 50), trashTextures);
	bool gaming = true;

	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	while(gaming) {
		player.update();
		trash.update();
		
		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;
		accumulator += frameTime;

		while(accumulator >= timeStep) {
			while(SDL_PollEvent(&event)) {
				switch(event.type) {
					case SDL_QUIT: {
						gaming = false;
						break;
					}
					default: {
						break;
					}
				}
			}
			accumulator -= timeStep;
		}

		//const float alpha = accumulator / timeStep;

		window.clear();
		window.render(trash);
		window.render(player);
		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		if(frameTicks < 1000 / window.getRefreshRate())
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}