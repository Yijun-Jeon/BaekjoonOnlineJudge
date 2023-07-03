#include <iostream>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> alpha(26);

char mostUsed(){
    char front = (char)(max_element(alpha.begin(),alpha.end()) - alpha.begin() + 'a');
    char back = (char)(alpha.rend() - max_element(alpha.rbegin(),alpha.rend()) + 'a' - 1);

    return front == back ? front - ('a' - 'A') : '?';
}

int main(void)
{
    
    string s;

    cin >> s;
    for(int i=0;i<s.length();i++){
        char c = tolower(s[i]);
        alpha[c - 'a'] += 1;
    }
    cout << mostUsed()<< endl;
    return 0;
}