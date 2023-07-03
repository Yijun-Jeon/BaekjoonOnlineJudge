#include <iostream>
using namespace std;
#define MAX_NUM 100

int main(void)
{
    int basket[MAX_NUM + 1] = {};
    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= MAX_NUM; i++)
        basket[i] = i;

    for (int idx = 0; idx < M; idx++)
    {
        int i, j;
        cin >> i >> j;
        swap(basket[i], basket[j]);
    }

    for (int i = 1; i <= N; i++)
        cout << basket[i] << ' ';
    cout << endl;
    return 0;
}
