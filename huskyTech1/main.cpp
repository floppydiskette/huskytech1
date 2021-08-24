#include "main.h"



//update code and stuff here


//todo: move this to a math class
float clip(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}



void input_update() {
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {

			case SDL_QUIT:
				explode();
				break;

			case SDL_KEYDOWN:
				handle_keyboard_movement(e, az_en);
				break;

			case SDL_KEYUP:
				switch (e.key.keysym.sym) { //i bet u guys love all these switch statements

					case SDLK_ESCAPE:
						explode();
						break;

					default:
						handle_keyboard_movement(e, az_en);
						break;

				}
				break;

		}
	}
}



void physics_update() {
	int speed = 75;

	az_en->SetPosition({ az_en->GetPosition().x + (az_en->velocity.x * speed * (float)deltaTime), az_en->GetPosition().y + (az_en->velocity.y * speed * (float)deltaTime) });
}



void update() {

}



void draw() {
	//Clear screen
	SDL_RenderClear(ht_renderer);

	az_en->Draw(ht_renderer);

	//Update screen
	SDL_RenderPresent(ht_renderer);
}



void handle_keyboard_movement(SDL_Event kev, Entity* en) {
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[C_forward])
		en->velocity.y = -1;
	else if (state[C_backward])
		en->velocity.y = 1;
	else
		en->velocity.y = 0;
	if (state[C_sleft])
		en->velocity.x = -1;
	else if (state[C_sright])
		en->velocity.x = 1;
	else
		en->velocity.x = 0;
}



//required code down here
int main(int argc, char* args[]) {

	//init
	if (init()) {
		
		//program ready, let's start running the code
		while (alive) {
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			deltaTime = ((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

			input_update();

			if (!alive) //the program may no longer be alive after the previous function, therefore we need to check and terminate if needed
				break;

			physics_update();

			update();

			draw();
		}

	}
	else {
		return -1;
	}

	return 0;
}


//initialize sdl stuff
bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}
	else {
		//no issue
		window = SDL_CreateWindow("husky tech 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			return false;
		}
		else {
			//no issue again, window now open
			ht_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (ht_renderer == NULL) {
				return false;
			}
			else {
				//init deltaTime
				NOW = SDL_GetPerformanceCounter();
				LAST = 0;
				deltaTime = 0;

				az_en = new Entity(new Sprite("data/character_ss.png", ht_renderer, 4, 3), {25, 25});
				alive = true;
				return true;
			}
		}
	}
}


//deallocate sdl stuff
void explode() {
	alive = false; //make sure that the main loop doesn't continue

	IMG_Quit();

	SDL_DestroyWindow(window);

	SDL_Quit();
}