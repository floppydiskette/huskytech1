#include <SDL.h>
#include <stdio.h> //for debugging

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screen_surface = NULL;

	//init
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL ERROR FUCK! %s\n", SDL_GetError());
	}
	else {
		//no issue
		window = SDL_CreateWindow("husky tech 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			printf("SDL ERROR WINDOW FUCK! %s\n", SDL_GetError());
		}
		else {
			//no issue again, window now open
			screen_surface = SDL_GetWindowSurface(window);

			//do draw code here

			//Fill the surface white
			SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0x00, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}