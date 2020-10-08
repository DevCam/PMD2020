#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DeckEmulator.h"

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

void initializeGame(GameState_ref g, enum SerializerStrategy strategy, const char* saveFilePath)
{
  g->deck = calloc(6, sizeof(char));
  initializeDeck(g->deck);
  g->deckCount = 5;
  g->inHand = 0;

  // serializer init
  g->serializer.SaveFilePath = strcpy(malloc(strlen(saveFilePath)+1), saveFilePath);
  g->serializer.Strategy = strategy;
  g->serializer.States = 0;
}

void endGame(GameState_ref g)
{
  free(g->deck);
  free(g->serializer.SaveFilePath);
  printf("Gracias por jugar!");
}

void saveGame(GameState_ref g, const char* saveFilePath)
{
  serialize(g, saveFilePath);
}

void loadGame(GameState_ref g, const char* saveFilePath)
{
  deserialize(g, saveFilePath);
}

void drawCard(GameState_ref g)
{
  if(g->inHand == 0 && g->deckCount - 1 >= 0)
  {
    g->inHand = g->deck[g->deckCount - 1];
    g->deckCount--;
  } else if(g->inHand) {
    printf("\t> Operación Ilegal: Ya se tiene una carta en la mano \n");
  } else {
    printf("\t> Operación Ilegal: El deck esta vacío \n");
  }
}

void returnToTop(GameState_ref g)
{
  if(g->inHand == 0)
  {
    printf("\t> Operación Ilegal: No se tiene carta en la mano \n");
  } else {
    g->deck[g->deckCount] = g->inHand;
    g->inHand = 0;
    g->deckCount++;
  }
}

void returnToBottom(GameState_ref g)
{
  if(g->inHand == 0)
  {
    printf("\t> Operación Ilegal: No se tiene carta en la mano \n");
  } else {
    memmove(g->deck+1, g->deck, 5 * sizeof(char));
    g->deck[0] = g->inHand;
    g->inHand = 0;
    g->deckCount++;
  }
}

void discard(GameState_ref g)
{
  if(g->inHand)
    g->inHand = 0;
  else
    printf("\t> Operación Ilegal: No se tiene carta en la mano \n");
}

void prettyPrint(const GameState_ref g)
{
  printf("{ ");
  for(int i=0; i < g->deckCount; i++)
    if(g->deck[i] == 'D')
      printf("[10]");
    else
      printf("[%c]", g->deck[i]);
  printf(" }");
  if(g->inHand == 'D')
    printf(" :: <10>\n");
  else
    printf(" :: <%c>\n", g->inHand);
}

void playDeckEmulator(GameState_ref g)
{
  char cmd[3] = {};
  printf("[p]ull | [t]op | [b]ottom | [d]iscard | [e]xit\n");
  prettyPrint(g);
  while(fgets(cmd, 3, stdin))
  {
    switch (cmd[0])
    {
    case 'p':
      drawCard(g);
      break;
    case 't':
      returnToTop(g);
      break;
    case 'b':
      returnToBottom(g);
      break;
    case 'd':
      discard(g);
      break;
    case 's':
      saveGame(g, "./data/savestate");
      printf("\t g saved!\n");
      break;
    case 'l':
      loadGame(g, "./data/savestate");
      printf("\t g Loaded!\n");
      break;
    case 'e':
      return;
    default:
      printf("\tNo cmd\n");
      continue;
      break;
    }
    prettyPrint(g);
  }
}