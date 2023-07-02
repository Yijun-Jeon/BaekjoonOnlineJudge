#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    if ((C % 60 + B) >= 60)
        A = (A + C / 60) >= 23 ? (A + C / 60) - 23 : (A + C / 60) + 1;
    else
        A = (A + C / 60) >= 24 ? (A + C / 60) - 24 : (A + C / 60);

    B = (C % 60 + B) >= 60 ? (C % 60 + B) - 60 : (C % 60 + B);

    cout << A << ' ' << B << endl;
    return 0;
}
