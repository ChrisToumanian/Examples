#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int health;
  void (*heal) ();
} Mob;

void heal(Mob *mob, int hp)
{
  mob->health += hp;
}

int main()
{
  Mob mob;

  mob.health = 100;
  mob.heal = heal;

  mob.heal(&mob, 50);
  
  printf("%d\n", mob.health);

  printf("%p\n", heal);
  
  return 0;
}
