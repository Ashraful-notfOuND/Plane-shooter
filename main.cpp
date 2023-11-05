#include"defs.hpp"
#include"init.hpp"

int main(int argc, char *argv[])
{
	App app;
	memset(&app, 0, sizeof(App));

	initSDL();

	while (1)
	{
		prepareScene();

		doInput();

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}
