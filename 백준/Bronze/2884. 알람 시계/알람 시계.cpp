#include <iostream>
using namespace std;

int main(void)
{
    int H, M;
    cin >> H >> M;

    if (M < 45)
        H = H == 0 ? 23 : H - 1;
    M = M < 45 ? M + 15 : M - 45;
    cout << H << ' ' << M << endl;
    return 0;
}
