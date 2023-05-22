/*
  UB C Programming Final Project
  Quadratic Formula Calculator
  Maxwell Gombos
*/
#include <stdio.h> //import input and output functions

int sqr(int term) { //define sqr funtion
  int index, root; //define variables
  if (term > 0) {
    //if the term is positive, calculate the whole square root of the term
    for (index = 1; index <= term; index++) {
      //find each factor of the term, and check if it is the square root of the term
      if (term%index == 0) {
        if (term/index == index) {
          //if it is the square root of the term, return the number
          root = index;
          return root;
        }
      }
    }
  }
  //if there is no whole square root, return -1
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
  int a, b, c, term, root; //define variables as integer
  int numeratorA, numeratorB, denominator;  //define variables as integer
  term = 0; //intitialize term variable

  printf("a: "); //ask user for input
  scanf("%d", &a); //accept user input
  printf("b: "); //ask user for input
  scanf("%d", &b); //accept user input
  printf("c: "); //ask user for input
  scanf("%d", &c); //accept user input

  //find the term of the square root (b^2-4ac)
  term = b * b;
  term += (-4 * a) * c;
  printf("%d", term);

  root = sqr(term); //call the sqr function
  if (root != -1) {
    //if the square root function found a whole root, calculate the quadratic formula
    printf("\n%d\n", root);
    numeratorA = (b * -1) + root; //find the numberator of -b + sqrt(b^2 - 4ac)
    numeratorB = (b * -1) - root; //find the numberator of -b - sqrt(b^2 - 4ac)
    denominator = (2 * a); //find the denominator
    printf("\n%d/%d, %d/%d\n", numeratorA, denominator, numeratorB, denominator); //print the output
  }
  else {
    //if the sqr function did not find a whole root, check if it is an imaginary number or parial root:
    if (term < 0) {
      //if it is an imaginary number, find the output of the formula using imaginary numbers to simplify the root
      term *= -1; //update term variable
      printf("\ni sqrt(%d)\n", term);
      numeratorA = (b * -1); //find the numberator of -b + sqrt(b^2 - 4ac)
      numeratorB = (b * -1); //find the numberator of -b - sqrt(b^2 - 4ac)
      denominator = (2 * a); //find the denominator
      printf("\n%d + i sqrt(%d)/%d, %d - i sqrt(%d)/%d\n", numeratorA, term, denominator, numeratorB, term, denominator); //print the output
    }
    else {
      //if it is a partial root, find the output of the formula using partial root
      printf("\nsqrt(%d)\n", term);
      numeratorA = (b * -1); //find the numberator of -b + sqrt(b^2 - 4ac)
      numeratorB = (b * -1); //find the numberator of -b - sqrt(b^2 - 4ac)
      denominator = (2 * a); //find the denominator
      printf("\n%d + sqrt(%d)/%d, %d - sqrt(%d)/%d\n", numeratorA, term, denominator, numeratorB, term, denominator); //print the output
    }
  }
  
  return 0;
}