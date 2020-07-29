#include <iostream>
#include <string>

using namespace std;

int main()
{
  int y = 5;
  int *x = &y;
  cout << &x << endl;         // 0x7ffc2401eb90, address of x pointer
  cout << *x << endl;         // 5, dereferenced value of y
  cout << x << endl;          // 0x7ffc2401eb8c, address of y
  cout << *(x) << endl;       // 5, dereferenced value of y
  
  //float f = 7.0;
  //short s = *(short*)&f;
  //cout << s << endl;                    // 0

  /* int i = 37;
  float f = *(float*)&i;
  cout << f << endl; */                 // 5.1848e-44

  /* int x = 60;
  float y = x;
  cout << y << endl; */

  /* char ch = 'A';
  short s = ch;
  cout << s << endl; */   // prints 65

  /* short s = 0b0000000001000001;   // binary 65
  char ch = s;
  cout << ch << endl; */             // prints 'A'

  /* string word = "cat";

  int c = (int) word[0];
  int a = (int) word[1];
  int t = (int) word[2];

  cout << &c << ", " << c << ", " << word[0] << "\n";
  cout << &a << ", " << a << ", " << word[1] << "\n";
  cout << &t << ", " << t << ", " << word[2] << "\n";

  string *pointer = &word;
  cout << "\n" << *(pointer) << "\n";
  cout << pointer << "\n"; */

  return 0;
}
