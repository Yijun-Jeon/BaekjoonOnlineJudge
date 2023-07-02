#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C;
    int award;

    cin >> A >> B >> C;

    if (A == B && B == C)
        award = 10000 + A * 1000;
    else if (A == B || A == C)
        award = 1000 + A * 100;
    else if (B == C)
        award = 1000 + B * 100;
    else
        award = max(max(A, B), C) * 100;

    cout << award << endl;
    return 0;
}
