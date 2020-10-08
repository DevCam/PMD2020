#include "DeckEmulator.h"

int main(void)
{
  struct GameState game;
  initializeGame(&game, BITMASK, "./data/savestate");
  playDeckEmulator(&game);
  endGame(&game);
  return 0;
}
