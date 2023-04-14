#include "Menu.h"

int main()
{
    initConsole();
    PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);
    MainMenu();
    return 0;
}