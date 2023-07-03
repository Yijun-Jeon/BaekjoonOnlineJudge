#include <iostream>
#include <string>
using namespace std;

bool isAlpha(char c){
    if('a' <= c && c <= 'z')
        return true;
    return false;
}

int isSpecialAlpha(string s){
    if(s == "lj" || s == "nj" || s == "dz=")
        return -1;
    return 0;
}

int main(void){
    string s;
    int cnt = 0;
    cin >> s;

    for(int i=0;i<s.length();i++){
        if(isAlpha(s[i]))
            cnt++;
    }
    if(s.length() >= 2){
        for(int i=0;i<s.length()-1;i++){
            cnt += isSpecialAlpha(s.substr(i,2));
        }
    }
    if(s.length() >= 3){
        for(int i=0;i<s.length()-2;i++){
            cnt += isSpecialAlpha(s.substr(i,3));
        }
    }
    cout << cnt << endl;
    return 0;
}