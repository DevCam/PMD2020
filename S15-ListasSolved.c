#include <stdio.h>
#include <stdlib.h>

// singly linked list
// doubly link list
struct Node {
  int value;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node* Node_ref;

// Crea un nuevo nodo con valor 'value' y retorna la referencia.
Node_ref newNode(int value);

// Imprime todos los valores de la lista
void PrintList(Node_ref node);

// Imprime todos los valores de la lista en orden inverso
void PrintListReverse(Node_ref node);

// libera la memoria de todos los elementos de una lista exceptuando el primero (first)
void DestroyList(Node_ref first);

// Agrega un nodo 'newNode' a la lista
void AddNode(Node_ref node, Node_ref newNode);

// Elimina el nodo 'nodeToRemove' de la lista, regresa 1 si se eliminó, 0 si no se eliminó.
int RemoveNode(Node_ref node, int nodeValue);

void AddToBeginning(Node_ref* first, Node_ref nodeToAdd);

int main()
{

  // Generamos el nodo inicial de la lista
  Node_ref first_ref = newNode(25);

  AddNode(first_ref, newNode(12));
  AddNode(first_ref, newNode(13));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(-123));

  PrintList(first_ref); // [25]->[12]->[13]->[5]->[-123]
  int wasRemoved = RemoveNode(first_ref, 5);

  if(wasRemoved)
    printf("\nSi eliminamos el 5!\n");
  else
    printf("\nNo eliminamos el 5!\n");

  AddToBeginning(&first_ref, newNode(52));
  PrintList(first_ref); // [52]->[25]->[12]->[13]->[-123]

  PrintListReverse(first_ref); // [-123]->[13]->[12]->[25]
  DestroyList(first_ref); // libera la memoria de los nodos adicionales
  return 0;
}

// agrega un elemento al principio de la lista
void AddToBeginning(Node_ref* head, Node_ref nodeToAdd)
{
  // Node_ref temp = head;
  // head = nodeToAdd;
  // head->next = temp;
  Node_ref temp = *head;
  *head = nodeToAdd;
  (*head)->next = temp;
}

Node_ref newNode(int value)
{
  Node_ref new = malloc(sizeof(struct Node));
  if(new == NULL)
    exit(EXIT_FAILURE);
  new->value = value;
  new->next = NULL;
  return new;
}

void PrintList(Node_ref node)
{
  while(node != NULL)
  {
    printf("[%d]->", node->value);
    node = node->next;
  }
}

void PrintListReverse(Node_ref node)
{
  if(node != NULL)
  {
    PrintListReverse(node->next);
    printf("%d ", node->value);
  }
}

void DestroyList(Node_ref node)
{
  if(node != NULL)
  {
    DestroyList(node->next);
    free(node);
  }
}

void AddNode(Node_ref first, Node_ref newNode)
{
  while(first->next != NULL)
    first = first->next;
  first->next = newNode;
}

// Esta garantizado que nodeValue existe en la lista
// y es un elemento unico.
// y no es first

// van a implementar RemoveNode pero sin restricciones:
// ahora ya es posible eliminar el primer nodo de la lista.
// ahora es posible que NO exista el elemento nodeValue dentro de la lista
// removeNode regresa 1 si elimino el elemnto correctamente, y regresa 0 si no lo encontro.
// tiene que eliminar TODOS los nodos con nodeValue
// [1]->[2]->[2]->[3], RemoveNode(2), [1]->[3]
int RemoveNode(Node_ref first, int nodeValue)
{
  if(first != NULL)
  {
    Node_ref nodeToRemove;
    Node_ref before = NULL;

    nodeToRemove = first;

    while (nodeToRemove != NULL && nodeToRemove->value != nodeValue)
    {
      before = nodeToRemove;
      nodeToRemove = nodeToRemove->next;
    }

    if(before != NULL)
    {
      before->next = nodeToRemove->next;
      free(nodeToRemove);
    }
    return 1;
  }
  return 0;
}

int Exists(Node_ref first, int nodeValue)
{
  //regresa 1 si el elemento esta presente, 0 si no existe
}

int Search(Node_ref first, int nodeValue)
{ 
  // regresa el indice de nodeValue (el primero que encuentre) o -1 si no existe.
  // [123]->[2]->[45]->[2]
  // Search(2) -> 1
  // Search(45) -> 2
  // search(124) -> -1
}