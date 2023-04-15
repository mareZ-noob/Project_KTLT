#include "Menu.h"

int main()
{
    initConsole();
    PlaySound(TEXT(MARIO_SOUND), NULL, SND_ASYNC);
    MainMenu();
    return 0;
}