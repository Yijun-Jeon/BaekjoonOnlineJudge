#include <iostream>
using namespace std;
#define MAX_NUM 100

int main(void)
{
    int basket[MAX_NUM + 1] = {};
    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        basket[i] = i;

    for (int idx = 0; idx < M; idx++)
    {
        int i, j;
        cin >> i >> j;
        for (int tmp = i; tmp <= (i + j) / 2; tmp++)
            swap(basket[tmp], basket[i + j - tmp]);
    }

    for (int i = 1; i <= N; i++)
        cout << basket[i] << ' ';
    cout << endl;
    return 0;
}
