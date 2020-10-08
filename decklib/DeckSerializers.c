#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DeckEmulator.h"

char parseNibble(int targetNibble, char byte)
{
  char first;
  if(targetNibble == 0)
    first = (byte >> 4) & 0x07; // drop nibble and handbit
  else
    first = byte & 0x07; // drop handbit

  switch(first)
  {
    case 0x00:
      return 0;
    break;
    case 0x01:
      return 'D';
    case 0x02:
      return 'J';
    case 0x03:
      return 'Q';
    case 0x04:
      return 'K';
    case 0x05:
      return 'A';
    default:
      return 'E'; // horrible error happened
  }
}

char getBitMask(char card)
{
  char mask = 0x00;
  switch(card)
  {
    case 0:
      return 0x00;
    case 'D':
      return 0x01;
    case 'J':
      return 0x02;
    case 'Q':
      return 0x03;
    case 'K':
      return 0x04;
    case 'A':
      return 0x05;
    default:
      return 0xFF; // horrible error happened
  }
  return mask;
}

void saveStateMask(GameState_ref g)
{
  FILE* saveFile = fopen(g->serializer.SaveFilePath, "w");
  char byteLoad = 0x00;

  for(int i=0; i < g->deckCount; i++)
  {
    if(byteLoad == 0x00)
    {
      // push first nibble to most significant bits of load
      byteLoad = getBitMask(g->deck[i]) << 4;
    } else {
      // add second nibble to least significant bits
      byteLoad = byteLoad | getBitMask(g->deck[i]);
    }
    // check if load is full and commit
    if((byteLoad & 0x07) != 0x00) {
      // byteload is full, commit to saveFile..
      fwrite(&byteLoad, 1, 1, saveFile);
      // and flush buffer
      byteLoad = 0x00;
    }
  }
  // check if hand is to be commited as a whole byte or as last nibble
  if(byteLoad == 0x00) {
    // hand will be the only element in its byte
    byteLoad = (getBitMask(g->inHand) | 0x08) << 4;
  } else {
    // we can append hand to the last nibble!
    byteLoad = byteLoad | (getBitMask(g->inHand) | 0x08);
  }
  fwrite(&byteLoad, 1, 1, saveFile);
  fclose(saveFile);
}

void loadStateMask(GameState_ref g)
{
  FILE* saveFile = fopen(g->serializer.SaveFilePath, "r");

  char saveBuffer[3];
  char byteLoad = 0x00;
  int byteCount = fread(saveBuffer, 1, 3, saveFile);

  if(byteCount == 0)
    return; // empty save

  int card_count = 0;
  for(int i = 0; i < byteCount - 1; i++)
  {
    byteLoad = saveBuffer[i];
    g->deck[card_count++] = parseNibble(0, byteLoad);
    g->deck[card_count++] = parseNibble(1, byteLoad);
  }
  // parse handByte
  byteLoad = saveBuffer[byteCount-1];
  // check if hand is in the first nibble!
  if((byteLoad & 0x80) != 0x00)
  {
    // hand is in first nibble, no additional cards to parse
    g->inHand = parseNibble(0, byteLoad);
  } else
  {
    // hand is in the second nibble, catch the last card!
    g->deck[card_count++] = parseNibble(0, byteLoad);
    g->inHand = parseNibble(1, byteLoad);
  }
  g->deckCount = card_count;

  fclose(saveFile);
}

void saveStateSimple(GameState_ref g)
{
  FILE* saveFile = fopen(g->serializer.SaveFilePath, "w");
  for(int i=0; i < g->deckCount; i++)
    fprintf(saveFile, "%c", g->deck[i]);
  fprintf(saveFile, "|%c", g->inHand);
  fclose(saveFile);
}

void loadStateSimple(GameState_ref g)
{
  FILE* saveFile = fopen(g->serializer.SaveFilePath, "r");
  char newGameState[7];
  fgets(newGameState, 7, saveFile);

  g->deckCount = strcspn(newGameState, "|");
  for(int i=0; i < g->deckCount; i++)
    g->deck[i] = newGameState[i];

  if(g->deckCount == strlen(newGameState))
    g->inHand = 0;
  else
    g->inHand = newGameState[g->deckCount+1];

  fclose(saveFile);
}

void serialize(GameState_ref g, const char* path)
{
  switch(g->serializer.Strategy)
  {
    case SIMPLE:
      saveStateSimple(g);
    break;
    case BITMASK:
      saveStateMask(g);
    break;
    case COMPRESS:
    break;
    default:
      fprintf(stderr, "Serializer cant find strategy");
    break;
  }
}

void deserialize(GameState_ref g, const char* path)
{
  switch(g->serializer.Strategy)
  {
    case SIMPLE:
      loadStateSimple(g);
    break;
    case BITMASK:
      loadStateMask(g);
    break;
    case COMPRESS:
    break;
    default:
      fprintf(stderr, "Serializer cant find strategy");
    break;
  }
}