#include <stdio.h>
#include <string.h>
#include "Stack.h"


// Recibe una expresion algebraica y evalua si los paren. estan bien formados
int CheckParenthesis(const char* );
int CheckParenthesisCorrect(const char*);
int isOpenParent(const char);
int isCloseParent(const char);
char getOpenParent(const char);

int main()
{
  const char* formula = "( ))";
  if(CheckParenthesisCorrect(formula))
  {
    printf("Los parent. de la formula son correctos!\n");
  } else {
    printf("Los parent. de la formula son incorrectos\n");
  }
}

// 1. Por cada parent. que abre, tiene que tener su cierre correspondiente.
// 2. Que no exista un parent. de cierre sin su apertura correspondiente.
// 3. "jerarquia de parent." -> ( { ) }

int CheckParenthesis(const char* formula)
{
  int parentCounter = 0;
  int llaveCounter = 0;
  int corcheteCounter = 0;

  while(*formula)
  {
    if(isOpenParent(*formula))
    {
      parentCounter++;
    } else if (isCloseParent(*formula)){
      parentCounter--;
      if(parentCounter < 0)
        return 0;
    }
    formula++;
  }

  return parentCounter == 0;
}

int CheckParenthesisCorrect(const char* formula)
{
  Stack_ref stack = new_stack();
  while(*formula)
  {
    if(isOpenParent(*formula))
    {
      push(stack, *formula);
    } else if (isCloseParent(*formula)){
      // ( , encontramos }, ], )
      char lastOpenSymbol = peek(stack); // lasOpenSymbol -> 0
      if(lastOpenSymbol == getOpenParent(*formula))
      {
        pop(stack);
      } else {
        return 0;
      }
    }
    formula++;
  }
  int stack_count = stack->count;
  destroy_stack(stack);

  if(stack_count != 0)
    return 0;
  return 1;
}

int isOpenParent(const char c)
{
  if(strchr("({[", c))
    return 1;
  return 0;
}
int isCloseParent(const char c)
{
  if(strchr(")}]", c))
    return 1;
  return 0;
}

char getOpenParent(const char c)
{
  switch(c){
    case ')':
      return '(';
    case ']':
      return '[';
    case '}':
      return '{';
    default:
      return 0;
  }
}

