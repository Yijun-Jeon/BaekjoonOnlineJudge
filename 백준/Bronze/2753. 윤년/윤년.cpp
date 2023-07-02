#include <iostream>
using namespace std;

int main(void)
{
    int year;
    cin >> year;

    if (!(year % 400))
        cout << 1 << endl;
    else if (!(year % 100))
        cout << 0 << endl;
    else
        cout << !(year % 4) << endl;
    return 0;
}
