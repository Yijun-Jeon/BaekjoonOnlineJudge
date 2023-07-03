#include <iostream>
using namespace std;

bool isGroup(string s){
    int alpha[26] = {};
    char lastChar = 'Z';
    for(int i=0;i<s.length();i++){
        if(s[i] != lastChar){
            if(alpha[s[i] - 'a'] != 0){
                return false;
            }
        }
        alpha[s[i]-'a'] = 1;
        lastChar = s[i];
    }
    return true;
}

int main(void)
{
    int N,cnt = 0;
    cin >> N;

    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        cnt += isGroup(s);
    }
    cout << cnt << endl;
    return 0;
}