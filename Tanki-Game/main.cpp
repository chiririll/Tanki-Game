#include "Game.h"
#include "MenuState.h"


int main(int argc, char* argv[])
{	
	Game* game = Game::GetInstance();
	game->PushState(new MenuState());
	game->Run();

	return 0;
}
