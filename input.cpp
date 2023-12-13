#include"defs.hpp"
void doKeyUp(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		app.keyboard[event->keysym.scancode] = 0;
	}
}
void doKeyDown(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		app.keyboard[event->keysym.scancode] = 1;
	}
}
void doInput(void){
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;

            case SDL_KEYDOWN:
                doKeyDown(&event.key);

                // if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL) {
                //     app.fire = 1;
                // }
                break;

            case SDL_KEYUP:
                doKeyUp(&event.key);

                // if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL) {
                //     app.fire = 1;
                // }
                break;

            default:
                break;
        }
    }
}