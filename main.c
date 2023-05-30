/*
  UB C Programming Final Project
  Quadratic Formula Calculator
  Maxwell Gombos
*/
#include <stdio.h> //import input and output functions
#include <string.h> //define main function

struct root {
  /*
  Root Struct: Stores the square root of a term
  inRoot: number inside of square root
  outRoot: number outside of square root
  */
    int inRoot;
    int outRoot;
};

struct root sqr(int term) {
  /*
  sqr Function:
  returns root struct
  finds the square root of the entered term. if it is a partial root, simplify the root instead
  Variable Guide:
  index: index variable, temporarily stores a number while it is being checked as the square root of the term
  output.outRoot: output, number outside of square root when simplified. comes from root struct
  output.inRoot:  output, number inside of square root when simplified. comes from root struct
  */
  struct root output; //call root struct as output
  int index; //define index variable
  output.outRoot = 1; //initialize outRoot
  output.inRoot = term; //initialize inRoot
  index = 2; //initialize index
  
  while ((index * index) <= output.inRoot) {
    //while index squared is not greater then the term:
    //check if index is the square root of the term
    if (output.inRoot%(index * index) == 0) {
      //if it is, update inRoot and outRoot
      output.inRoot = output.inRoot / (index * index);
      output.outRoot = output.outRoot * index;
    }
    else {
      //if it isn't, increment index by 1
      index += 1;
    }
  }
  return output; //return updated root struct
}

int gcf(int a, int b) {
  /*
  gcf Function:
  finds the greatest common factor of two numbers
  it does this by checking if b is equal to 0
  if it is, return a as gcf
  if not, set b to the remainder of a/b and check again
  Variable Guide:
  a: first number to find the gcf of
  b: second number to find the gcf of
  */
  if (b == 0) {
    //if b is equal ot 0, gcf is equal to a
    return a;
  }
  else {
    //if be is not equal to 0
    //update b variable
    //call gcf function again
    return gcf(b, a%b);
  }
}

struct fraction {
  /*
  faction Struct:
  stores integer numerator and denominator of the two fractions
  Variable Guide:
  numeratorA: numerator of first output fraction
  numeratorB: numerator of second output fraction
  denominatorA: denominator of first output fraction
  denominatorB: denominator of secodn output fraction
  */
  int numeratorA;
  int denominatorA;
  int numeratorB;
  int denominatorB;
};

int main(void) {
    /*
    Quadratic Equation:
    ax^2 + bx + c
    Quadratic Formula:
    -b ± sqr(b^2 - 4ac)
    -------------------
            2a
    Variable Guide:
    a: a variable in quadratic equation
    b: b variable in quadratic equation
    c: c variable in quadratic equation
    isTermNegative: stores if the term of the square root is negative
    factor: stores gcf of numerator and denominator of the output fraction, used when simplifying fractions
    term: term of the square root in quadratic formula (b^2-4ac)
    fraction: struct used to store numerator and denominator of output
    root: struct used to store the output of the square root
    */
  int a, b, c, isTermNegative, factor, term; //define variables as integers
  struct fraction output; //initialize fraction struct as output
  struct root root; //initialize root struct as root
  isTermNegative = 0; //initialize isTermNegative as 0 (term is positive)

  printf("This program allows you to enter the three coefficients of a quadratic equation. It will then enter those into the quadratic formula to find the roots of the quadratic equation.\nQuadratic Equation:\n\ty = ax^2 + bx + c\nQuadratic Formula:\n\t-b +/- sqrt(b^2 - 4ac)\n\t----------------------\n\t          2a\n\n");

  //get a, b, and c variables
  printf("a: ");
  scanf("%d", &a);
  printf("b: ");
  scanf("%d", &b);
  printf("c: ");
  scanf("%d", &c);

  printf("\nYour Quadratic Equation:\ny = %dx^2 + %dx + %d\n", a, b, c); //print quadratic equation
  printf("Your Quadratic Formula:\n-(%d) +/- sqrt((%d)^2 - 4(%d)(%d))\n-----------------------------------\n               2(%d)\n", b, b, a, c, a); //print quadratic formula

  //calculate square root term (b^2-4ac)
  term = b * b;
  term = term - ((4 * a) * c);

   if (term > 0) {
     //if the term is positive:
     //call the sqr function to find the square root of the term
     root = sqr(term);
   }
   if (term < 0) {
     //if the term is negative:
     term *= -1; //convert to positive
     isTermNegative = 1; //update isTermNegative variable to 1 (term is negative)
     root = sqr(term); //call sqr function to find the square root of the term
   }
  
   if (root.inRoot == 1 && isTermNegative == 0) {
     /*
     If the term is positive and a whole root:
     Split the quadratic formula into two outputs (-b + sqr(b^2-4ac) and -b - sqr(b^2-4ac))
     find the numerator for each
     find the denominator for each
     simplify the two fractions
     output for the user
     */
     output.numeratorA = (-1 * b) + root.outRoot; //find numeratorA
     output.denominatorA = 2 * a; //find denominatorA
     output.numeratorB = (-1 * b) - root.outRoot; //find numeratorB
     output.denominatorB = 2 * a; //find denominatorB
     factor = gcf(output.numeratorA, output.denominatorA); //find the gcf of the numerator and denominator for the first output fraction
     //simplify first output fraction
     output.numeratorA /= factor;
     output.denominatorA /= factor;
     factor = gcf(output.numeratorB, output.denominatorB); //find the gcf of the numerator and denominator for the second output fraction
     //simplify second output fraction
     output.numeratorB /= factor;
     output.denominatorB /= factor;
     printf("\nQuadratic Equation Roots:\n%d/%d, %d/%d\n", output.numeratorA, output.denominatorA, output.numeratorB, output.denominatorB); //print formula output
   }
   else if (root.inRoot != 1 && isTermNegative == 0) {
     /*
     If the term is positive and a partial root:
     Split the quadratic formula into two outputs (-b + sqr(b^2-4ac) and -b - sqr(b^2-4ac))
     find the numerator for each
     find the denominator for each
     output for the user
     */
     output.denominatorA = 2 * a; //find denominatorA
     output.denominatorB = 2 * a; //find denominatorB
     output.numeratorA = -1 * b; //find numeratorA
     output.numeratorB = -1 * b; //find numeratorB
     printf("\nQuadratic Equation Roots:\n%d + %d sqrt(%d)/%d, %d - %d sqrt(%d)/%d\n", output.numeratorA, root.outRoot, root.inRoot, output.denominatorA, output.numeratorB, root.outRoot, root.inRoot, output.denominatorB); //print formula output
   }
   else if (root.inRoot == 1 && isTermNegative == 1) {
     /*
     If the term is negative and a whole root:
     Split the quadratic formula into two outputs (-b + sqr(b^2-4ac) and -b - sqr(b^2-4ac))
     find the numerator for each
     find the denominator for each
     output for the user
     */
     output.denominatorA = 2 * a; //find denominatorA
     output.denominatorB = 2 * a; //find denominatorB
     output.numeratorA = -1 * b; //find numeratorB
     output.numeratorB = -1 * b; //find denominatorB
     printf("\nQuadratic Equation Roots:\n%d + %di/%d, %d - %di/%d\n", output.numeratorA, root.outRoot, output.denominatorA, output.numeratorB, root.outRoot, output.denominatorB); //print formula output
   }
   else if (root.inRoot != 1 && isTermNegative == 1) {
     /*
     If the term is negative and a partial root:
     Split the quadratic formula into two outputs (-b + sqr(b^2-4ac) and -b - sqr(b^2-4ac))
     find the numerator for each
     find the denominator for each
     output for the user
     */
     output.denominatorA = 2 * a; //find denominatorA
     output.denominatorB = 2 * a; //find denominatorB
     output.numeratorA = -1 * b; //find numeratorA
     output.numeratorB = -1 * b; //find numeratorB
     printf("\nQuadratic Equation Roots:\n%d + %di sqrt(%d)/%d, %d - %di sqrt(%d)/%d\n", output.numeratorA, root.outRoot, root.inRoot, output.denominatorA, output.numeratorB, root.outRoot, root.inRoot, output.denominatorB); //print output of formula
  }
  printf("\nProgram Complete!\n"); //output statement
}