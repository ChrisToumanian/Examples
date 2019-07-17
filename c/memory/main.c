#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void allocateMemory();

int main(int argc, char *argv[])
{
  allocateMemory();
  return 0;
}

void allocateMemory()
{
  char *i;
  i = malloc(sizeof(char) * 4);
  *i = 65;
  *(i+1) = 66;
  *(i+2) = 67;
  *(i+3) = 43;
  printf("%s", *i);
}
