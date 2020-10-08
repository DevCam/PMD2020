#ifndef _DECK_EMULATOR_GUARD
#define _DECK_EMULATOR_GUARD

  enum SerializerStrategy{
    SIMPLE=0,
    BITMASK=1,
    COMPRESS=2
  };

  struct DeckSerializer
  {
    enum SerializerStrategy Strategy;
    char* SaveFilePath;
    char** States;
  };

  struct GameState{
    char* deck;
    int deckCount;
    char inHand;

    struct DeckSerializer serializer;
  };

  typedef struct GameState* GameState_ref;

  void playDeckEmulator(GameState_ref);
  void initializeGame(GameState_ref, enum SerializerStrategy, const char*);
  void endGame(GameState_ref);

  void saveGame(GameState_ref, const char*);
  void loadGame(GameState_ref, const char*);

  void drawCard(GameState_ref);
  void returnToTop(GameState_ref);
  void returnToBottom(GameState_ref);
  void discard(GameState_ref);
  void prettyPrint(GameState_ref);

  void serialize(GameState_ref, const char*);
  void deserialize(GameState_ref, const char*);
  void setSerializationStrategy(enum SerializerStrategy);

#endif