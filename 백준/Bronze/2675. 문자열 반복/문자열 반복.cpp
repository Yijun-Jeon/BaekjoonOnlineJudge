#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int T, R;
    string S;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> R;
        cin >> S;

        char P[R * S.size() + 1];
        int PIdx = 0;
        for (int j = 0; j < S.size(); j++)
        {
            for (int k = 0; k < R; k++)
                P[PIdx++] = S[j];
        }
        P[PIdx] = 0;
        cout << P << endl;
    }
    return 0;
}