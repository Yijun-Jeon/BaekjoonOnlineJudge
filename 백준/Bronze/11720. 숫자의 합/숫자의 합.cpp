#include <iostream>
using namespace std;

int main(void)
{
    int N, sum = 0;
    string S;

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        sum += ((int)S[i] - '0');

    cout << sum << endl;
    return 0;
}