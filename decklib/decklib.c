#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "deckLib.h"

// devcams Libs copyleft :)
// implementar las funciones del header file.
void initializeDeck(char* deck)
{
  srand(time(NULL));
  char cardsToAdd[] = {'D', 'J', 'Q', 'K', 'A'};
  for(int i = 0 ; i < 5; i++)
  {
    int addIndex = rand() % 5;
    while(cardsToAdd[addIndex % 5] == 0)
      addIndex++;
    deck[i] = cardsToAdd[addIndex % 5];
    cardsToAdd[addIndex % 5] = 0;
  }
}

GameStateRef DE_newDeckEmulator()
{
  GameStateRef game = malloc(sizeof(struct GameState));
  game->deck = calloc(6, sizeof(char));
  initializeDeck(game->deck);
  game->deckCount = 5;
  game->inHand = 0;
  return game;
}

void DE_endGame(GameStateRef game)
{
  free(game->deck);
  printf("Gracias por jugar!");
}

void DE_drawCard(GameStateRef game)
{
  if(game->inHand == 0 && game->deckCount - 1 >= 0)
  {
    game->inHand = game->deck[game->deckCount - 1];
    game->deckCount--;
  } else if(game->inHand) {
    printf("\t> Operación Ilegal: Ya se tiene una carta en la mano \n");
  } else {
    printf("\t> Operación Ilegal: El deck esta vacío \n");
  }
}

void DE_returnToTop(GameStateRef game)
{
  if(game->inHand == 0)
  {
    printf("\t> Operación Ilegal: No se tiene carta en la mano \n");
  } else {
    game->deck[game->deckCount] = game->inHand;
    game->inHand = 0;
    game->deckCount++;
  }
}

void DE_returnToBottom(GameStateRef game)
{
  if(game->inHand == 0)
  {
    printf("\t> Operación Ilegal: No se tiene carta en la mano \n");
  } else {
    memmove(game->deck+1, game->deck, 5 * sizeof(char)); // es equivalente a sus ciclos for
    game->deck[0] = game->inHand;
    game->inHand = 0;
    game->deckCount++;
  }
}

void DE_discard(GameStateRef game)
{
  if(game->inHand)
    game->inHand = 0;
  else
    printf("\t> Operación Ilegal: No se tiene carta en la mano \n");
}

void DE_prettyPrint(GameStateRef game)
{
  printf("{ ");
  for(int i=0; i < game->deckCount; i++)
    if(game->deck[i] == 'D')
      printf("[10]");
    else
      printf("[%c]", game->deck[i]);
  printf(" }");
  if(game->inHand == 'D')
    printf(" :: <10>\n");
  else
    printf(" :: <%c>\n", game->inHand);
}

void DE_playDeckEmulator(GameStateRef game)
{
  char cmd[2] = {};
  printf("[p]ull | [t]op | [b]ottom | [d]iscard | [e]xit\n");
  DE_prettyPrint(game);
  while(fgets(cmd, 2, stdin))
  {
    switch (cmd[0])
    {
    case 'p':
      DE_drawCard(game);
      break;
    case 't':
      DE_returnToTop(game);
      break;
    case 'b':
      DE_returnToBottom(game);
      break;
    case 'd':
      DE_discard(game);
      break;
    case 'e':
      return;
    default:
      DE_prettyPrint(game);
      break;
    }
  }
}