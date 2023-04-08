#include "Menu.h"

int main() {
    clearScreen();
    initConsole();
    PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);
    MainMenu();
    return 0;
}