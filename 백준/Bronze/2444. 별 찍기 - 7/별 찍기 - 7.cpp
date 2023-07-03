#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = N - i; j > 0; j--)
            cout << ' ';
        for (int k = 0; k < 2 * i - 1; k++)
            cout << '*';
        cout << endl;
    }
    for (int i = N + 1; i <= N * 2 - 1; i++)
    {
        for (int j = 0; j < i - N; j++)
            cout << ' ';
        for (int k = 0; k < 2 * (2 * N - i) - 1; k++)
            cout << '*';
        cout << endl;
    }

    return 0;
}