#include <cstdio>

int main()
{
  ((void(*)())0x400510)();
}

void not_main()
{
  puts("Hello, World!");
}
