#include <iostream>
#include <string>
#include "math.h"

using namespace std;

int main(int argc, char *argv[])
{
    double a;
    double b;

    cout << "Choose two numbers to divide.\n";
    cin >> a;
    cin >> b;
    cout << Math::Divide(a, b) << "\n";
    return 0;
}
