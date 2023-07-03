#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int words[26];
    memset(words, -1, sizeof(words));

    string S;
    cin >> S;

    for (int i = 0; i < S.size(); i++)
        words[S[i] - 'a'] = words[S[i] - 'a'] == -1 ? i : words[S[i] - 'a'];

    for (int word : words)
        cout << word << ' ';
    cout << endl;
    return 0;
}