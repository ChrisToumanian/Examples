//main(c){for(;c=~getchar();rand()%5&&putchar(~c));}

main(c)
{
  srand(&c);
  int x = rand() % 256;
  printf("%d", x);
  for(srand(&c); c = ~getchar(); rand() % 5 && putchar(~c));
}

/* Explanation: Compile with gcc & -w

  #include<stdio.h>                     isn't required

  main(c)                               specifying void isn't necessary, neither is char
  
  for(; c = ~getchar(); putchar(~c));   This gets characters and prints them out in a loop

*/
