#include <stdio.h>
#include <stdlib.h>

#define NDAYS 20

struct Day
{
  int high;
  int low;
};

int main()
{
  struct Day *days = malloc(sizeof(struct Day) * NDAYS);
  
  for (int i = 0; i < NDAYS; i++)
  {
    days[i].high = 72;
    days[i].low = 55;
  }

  for (int i = 0; i < NDAYS; i++)
  {
    printf("%2d%6d\n", days[i].high, days[i].low);
  }
}
