#include <stdio.h>

int main()
{
  FILE *file;
  char c;
  
  file = fopen("file.txt", "r");
  
  while (1)
  {
    c = fgetc(file);
    if (feof(file)) 
      break ;
    printf("%c", c);
  }

  fclose(file);
  
  return 0;
}
