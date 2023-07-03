#include <iostream>
using namespace std;
#define MAX_NUM 100

int main(void)
{
    int basket[MAX_NUM + 1] = {};
    int N, M;
    cin >> N >> M;

    for (int idx = 0; idx < M; idx++)
    {
        int i, j, k;
        cin >> i >> j >> k;

        for (int ball = i; ball <= j; ball++)
            basket[ball] = k;
    }
    for (int i = 1; i <= N; i++)
        cout << basket[i] << ' ';
    cout << endl;
    return 0;
}
