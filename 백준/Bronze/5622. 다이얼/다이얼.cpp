#include <iostream>
#include <string>
using namespace std;

int CharToNum(char c)
{
    int alpha = c - 'A';
    if (alpha < 15)
        return alpha / 3 + 3;
    else if (15 <= alpha && alpha <= 18)
        return 7 + 1;
    else if (18 < alpha && alpha < 22)
        return 8 + 1;
    else
        return 9 + 1;
}

int main(void)
{
    string S;
    int sum = 0;

    cin >> S;
    for (int i = 0; i < S.size(); i++)
        sum += CharToNum(S[i]);

    cout << sum << endl;
    return 0;
}