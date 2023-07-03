#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int sum;
    cin >> n;

    if (n & 1)
        sum = (n + 1) * (n / 2 + 1) - (n + 1) / 2;
    else
        sum = (n + 1) * (n / 2);
    cout << sum << endl;
    return 0;
}
