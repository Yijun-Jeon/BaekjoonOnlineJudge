#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int result = 0;
    string S;
    getline(cin, S);

    if (S.empty() || (S.size() == 1 && S[S.size() - 1] == ' '))
    {
        cout << result << endl;
        return 0;
    }

    int startIdx = S[0] == ' ' ? 1 : 0;
    int endIndx = S[S.size() - 1] == ' ' ? S.size() - 1 : S.size();

    for (int i = startIdx; i < endIndx; i++)
        result = S[i] == ' ' ? result + 1 : result;

    cout << ++result << endl;
    return 0;
}