#include <stdio.h>

#define LOWER 0 // lower limit of temperature scale
#define UPPER 300 // upper limit of temperature scale
#define STEP 20 // step size

// print Fahrenheit-Celsius table
main()
{
  float fahr, celsius;

  fahr = LOWER;

  while (fahr <= UPPER) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %8.2f\n", fahr, celsius);
    fahr += STEP;
  }
}
