#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  int tuna = 19; // declare int tuna to equal 19
  int *pTuna = &tuna; // declare pointer and assign it to the address of tuna
  
  printf("Address \t Name \t Value \n");
  printf("%p \t %s \t %d \n", &tuna, "tuna", tuna);
  printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);
  printf("%p \t %s \t %p \n", &pTuna, "tuna", pTuna);

  printf("\n *pTuna: %d \n", *pTuna );  // dereference pointer

  *pTuna = 71;  // sets value of *pTuna, which points to tuna, to 71

  printf("\n *pTuna: %d \n", *pTuna);
  printf("tuna: %d \n", tuna);

  printf("\n %p \n", pTuna);

  printf("%d \n", *pTuna + 1);

  printf("%d \n", *(pTuna + 1));
  printf("%p \n", pTuna + 1);
  
  return 0;
}
