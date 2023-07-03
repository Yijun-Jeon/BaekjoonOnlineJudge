#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = N - i; j > 0; j--)
        {
            cout << ' ';
        }
        for (int j = 0; j < i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
