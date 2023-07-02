#include <iostream>
using namespace std;

int main(void)
{
    int x, y;
    int n;
    cin >> x >> y;

    if (x > 0 && y > 0)
        n = 1;
    else if (x > 0 && y < 0)
        n = 4;
    else if (x < 0 && y > 0)
        n = 2;
    else
        n = 3;
    cout << n << endl;
    return 0;
}
