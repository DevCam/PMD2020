//
// Created by Josean Camarena on 19/11/20.
//

#ifndef HASHMAP_MAP_H
#define HASHMAP_MAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
  char* key;
  char* value;
  struct node* next;
}Node;

typedef struct {
  Node** hashTable;
  int tableSize;
  int (*HashFunction)(char*);
}Map;

Map* map_create(int tableSize, int (*HashFunction)(char*));
void map_put(Map* m, char* key, char* value); // esto agrega elementos al set
char* map_get(Map* m, char* key); // esto obtiene elementos
int map_contains(Map* m, char* key);

#endif //HASHMAP_MAP_H
