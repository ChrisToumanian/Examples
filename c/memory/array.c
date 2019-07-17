#include <stdio.h>

int main()
{
  int meatballs[5] = {7,9,43,21,3};

  // meatballs[6] = 3; // overwrites memory outside of the array
  
  printf("Element \t Address \t \t Value \n");
  
  for (int i = 0; i < 5; i++)
  {
    printf("meatballs[%d] \t %p \t %d \n", i, &meatballs[i], meatballs[i]);
  }

  printf("meatballs \t \t %p \n", meatballs);  // The value of meatballs is the address of the first element. It is a pointer

  printf("*meatballs: %d \n", *meatballs); // dereference meatballs to see its value

  printf("*meatballs: %d \n", *(meatballs + 1)); // increment the array pointer's memory value

  printf("*meatballs: %d \n \n", *meatballs + 1); // Add 1 to the value of the array

  
  for (int i = 0; i < 50; i++)
  {
    printf("*meatballs: %40d %p \n", *(meatballs + i), &meatballs[i]);
  }

  char abc[3] = {'a', 'b', 'c'};
  
  for (int i = 0; i < 100; i++)
  {
    printf("%c", abc[i]);
  }

  char word[3] = "harry";

  printf("\n %s \n", word);
  
  for (int i = 0; i < 50; i++)
  {
    printf("%c", word[i]);
  }
}
