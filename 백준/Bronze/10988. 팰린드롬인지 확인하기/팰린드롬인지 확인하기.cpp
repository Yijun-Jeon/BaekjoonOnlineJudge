#include <iostream>
using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int strLen = s.length();
    for(int i=0;i<strLen/2;i++){
        if(s[i] != s[strLen- 1 - i]){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}