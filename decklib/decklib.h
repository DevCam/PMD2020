// Header files
// namespaces
// refactorizar == refactor.
#ifndef _DECK_EMULATOR_GUARD_H
#define _DECK_EMULATOR_GUARD_H

struct GameState{
  char* deck;
  int deckCount;
  char inHand;
};

typedef struct GameState* GameStateRef;

void DE_playDeckEmulator(GameStateRef);
GameStateRef DE_newDeckEmulator();
void DE_endGame(GameStateRef);

void DE_drawCard(GameStateRef);
void DE_returnToTop(GameStateRef);
void DE_returnToBottom(GameStateRef);
void DE_discard(GameStateRef);
void DE_prettyPrint(GameStateRef);

#endif