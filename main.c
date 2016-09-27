#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100
int main()
{
  int type;
  double op2;
  char s[MAXOP];
  while((type = getop(s)) != EOF) {
    switch(type) {
    case NUMBER:
      printf("NUMBER: %s\n",s);
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / pop());
      else
        printf("Error: divisor 0\n");
      break;
    case '\n':
      printf("\t%.8g\n",pop());
      break;
    default:
      break;
    }
  }
  return 0;
}