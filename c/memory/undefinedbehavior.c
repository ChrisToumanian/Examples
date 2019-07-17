#include <stdio.h>

int main()
{
  // int x = 1;
  char x = 'a';
  int y[5] = {1,2,3,4,5};

  // int *px = &x
  char *px = &x;

  printf("%p\n", &x);
  printf("%p\n\n", &y);

  for (int i = 0; i < 50; i++)
  {
    printf("%x ", *(px + i) & 0xff);
  }
  
  /* for (int i = 0; i < 20; i++)
  {
    printf("%d\n", *(px + i));
  } */
}
