#include <stdio.h>
#include <stdlib.h>

typedef struct Mob
{
  int health;
  int (*die) ();
} Mob;

int die()
{
  return 666;
}

int main()
{
  Mob mob;

  mob.health = 10;
  mob.die = die;

  printf("%d\n", mob.die());
    
  return 0;
}
