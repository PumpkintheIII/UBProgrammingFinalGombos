/*
  UB C Programming Final Project
  Quadratic Formula Calculator
  Maxwell Gombos
*/
#include <stdio.h>

int sqr(int term) {
  int index, root;
  if (term > 0) {
    for (index = 1; index <= term; index++) {
      if (term%index == 0) {
        if (term/index == index) {
          root = index;
          return root;
        }
      }
    }
  }
  return term;
}

int main(void) {
  /*
    Variable Guide:

    Equation Part Guide:
    -b ± sqrt(b^2 - 4ac) / 2a
    part1: -b
    part2: b^2
    part3: -4ac
    part4: 2a
    term: b^2 - 4ac
  */
  int a, b, c, term, root;
  term = 0;

  printf("a: ");
  scanf("%d", &a);
  printf("b: ");
  scanf("%d", &b);
  printf("c: ");
  scanf("%d", &c);

  term = b * b;
  term += (-4 * a) * c;
  printf("%d", term);

  root = sqr(term);
  printf("\n%d", root);
  
  return 0;
}