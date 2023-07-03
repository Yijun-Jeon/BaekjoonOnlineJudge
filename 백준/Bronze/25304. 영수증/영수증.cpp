#include <iostream>
using namespace std;

int main(void)
{
    int X, N, a, b;
    int sum = 0;

    cin >> X >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        sum += a * b;
    }
    cout << (sum == X ? "Yes" : "No") << endl;
    return 0;
}
