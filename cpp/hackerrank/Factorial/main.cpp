#include <iostream>

using namespace std;

int main()
{
    int n, r; // R objects taken from N set

    cout << "R objects from N set: ";
    cin >> r >> n;
    
    int f = n;

    for (int i = n - 1; i > n - r; i--)
    {
        f *= i;
    }

    cout << f << endl;

    return 0;
}
