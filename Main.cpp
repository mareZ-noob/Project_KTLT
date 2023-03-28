#include "Menu.h"

int main() {
    clearScreen();
    PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);
    MainMenu();
    return 0;
}