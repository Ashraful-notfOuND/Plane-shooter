#include"defs.hpp"
#include"init.hpp"

int main()
{
	long then;
	float remainder;

	memset(&app, 0, sizeof(App));

	initSDL();

	// atexit(cleanup);

	initStage();

	then = SDL_GetTicks();

	remainder = 0;

	while (1)
	{
		prepareScene();

		doInput();

		app.delegate.logic();

		app.delegate.draw();

		presentScene();

		capFrameRate(&then, &remainder);
	}

	return 0;
}