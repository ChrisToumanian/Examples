#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *file;
  
  file = fopen("write.txt", "w+");
  fprintf(file, "%s %s %s %d", "We", "are", "in", 2012);
  fclose(file);
  
  return 0;
}
