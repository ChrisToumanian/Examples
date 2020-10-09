#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int it;
  long lng;
  char ch;
  float flt;
  double dbl;

  scanf("%i %ld %c %f %lf", &it, &lng, &ch, &flt, &dbl);
  printf("%i\n%ld\n%c\n%.3f\n%.9lf\n", it, lng, ch, flt, dbl);

  return 0;
}
