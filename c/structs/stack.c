#include <stdio.h>

#define NDAYS 20

typedef struct
{
  int high;
  int low;
} Day;

Day days[NDAYS];

int main()
{
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
