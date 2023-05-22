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
  return -1;
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
  int numeratorA, numeratorB, denominator;
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
  if (root != -1) {
    printf("\n%d\n", root);
    numeratorA = (b * -1) + root;
    numeratorB = (b * -1) - root;
    denominator = (2 * a);
    printf("\n%d/%d, %d/%d\n", numeratorA, denominator, numeratorB, denominator);
  }
  else {
    if (term < 0) {
      term *= -1;
      printf("\ni sqrt(%d)\n", term);
      numeratorA = (b * -1);
      numeratorB = (b * -1);
      denominator = (2 * a);
      printf("\n%d + i sqrt(%d)/%d, %d - i sqrt(%d)/%d\n", numeratorA, term, denominator, numeratorB, term, denominator);
    }
    else {
      printf("\nsqrt(%d)\n", term);
      numeratorA = (b * -1);
      numeratorB = (b * -1);
      denominator = (2 * a);
      printf("\n%d + sqrt(%d)/%d, %d - sqrt(%d)/%d\n", numeratorA, term, denominator, numeratorB, term, denominator);
    }
  }
  
  return 0;
}