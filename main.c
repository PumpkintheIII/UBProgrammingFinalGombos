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
  int a, b, c, term, root, index; //define variables as integer
  int numeratorA, numeratorB, denominatorA, denominatorB, outA, outB;  //define variables as integer
  term = 0; //intitialize term variable
  outA = 0;
  outB = 0;

  printf("a: "); //ask user for input
  scanf("%d", &a); //accept user input
  printf("b: "); //ask user for input
  scanf("%d", &b); //accept user input
  printf("c: "); //ask user for input
  scanf("%d", &c); //accept user input

  //find the term of the square root (b^2-4ac)
  term = b * b;
  term += (-4 * a) * c;

  root = sqr(term); //call the sqr function
  if (root != -1) {
    //if the square root function found a whole root, calculate the quadratic formula
    numeratorA = (b * -1) + root; //find the numberator of -b + sqrt(b^2 - 4ac)
    numeratorB = (b * -1) - root; //find the numberator of -b - sqrt(b^2 - 4ac)
    denominatorA = (2 * a); //find the denominator
    denominatorB = (2 * a); //find the denominator
    if (numeratorA > denominatorA) {
      if (numeratorA%denominatorA == 0) {
        numeratorA = numeratorA/denominatorA;
        denominatorA = 1;
      }
      else {
        while (numeratorA > denominatorA) {
          numeratorA -= denominatorA;
          outA += 1;
        }
      }
    }
    else {
      for (index = 1; index < denominatorA; index++) {
        if (denominatorA%index == 0) {
          if (numeratorA%index == 0) {
            numeratorA = numeratorA/index;
            denominatorA = denominatorA/index;
          }
        }
      }
    }
    if (numeratorB > denominatorB) {
      if (numeratorB%denominatorB == 0) {
        numeratorB = numeratorB/denominatorB;
        denominatorB = 1;
      }
      else {
        while (numeratorB > denominatorB) {
          numeratorB -= denominatorB;
          outB += 1;
        }
      }
    }
    else {
      for (index = 1; index < denominatorB; index++) {
        if (denominatorB%index == 0) {
          if (numeratorB%index == 0) {
            numeratorB = numeratorB/index;
            denominatorB = denominatorB/index;
          }
        }
      }
    }
    if (outA != 0 && outB == 0) {
      printf("\n%d %d/%d, %d/%d\n", outA, numeratorA, denominatorA, numeratorB, denominatorB); //print the output
    }
    else if (outA == 0 && outB != 0) {
      printf("\n%d/%d, %d %d/%d\n", numeratorA, denominatorA, outB, numeratorB, denominatorB); //print the output
    }
    else if (outA != 0 && outB != 0) {
      printf("\n%d %d/%d, %d %d/%d\n", outA, numeratorA, denominatorA, outB, numeratorB, denominatorB); //print the output
    }
    else {
      printf("\n%d/%d, %d/%d\n", numeratorA, denominatorA, numeratorB, denominatorB); //print the output
    }
  }
  else {
    //if the sqr function did not find a whole root, check if it is an imaginary number or parial root:
    if (term < 0) {
      //if it is an imaginary number, find the output of the formula using imaginary numbers to simplify the root
      term *= -1; //update term variable
      numeratorA = (b * -1); //find the numberator of -b + sqrt(b^2 - 4ac)
      numeratorB = (b * -1); //find the numberator of -b - sqrt(b^2 - 4ac)
      denominatorA = (2 * a); //find the denominator
      denominatorB = (2 * a); //find the denominator
      printf("\n%d + i sqrt(%d)/%d, %d - i sqrt(%d)/%d\n", numeratorA, term, denominatorA, numeratorB, term, denominatorB); //print the output
    }
    else {
      //if it is a partial root, find the output of the formula using partial root
      numeratorA = (b * -1); //find the numberator of -b + sqrt(b^2 - 4ac)
      numeratorB = (b * -1); //find the numberator of -b - sqrt(b^2 - 4ac)
      denominatorA = (2 * a); //find the denominator
      denominatorB = (2 * a); //find the denominator
      printf("\n%d + sqrt(%d)/%d, %d - sqrt(%d)/%d\n", numeratorA, term, denominatorA, numeratorB, term, denominatorB); //print the output
    }
  }
  
  return 0;
}