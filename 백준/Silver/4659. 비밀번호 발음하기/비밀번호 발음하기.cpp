#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

bool checkPwdValid(string pwd){
    bool valid = false;
    for(int i=0;i<(int)pwd.size();i++){
        if(isVowel(pwd[i])){
            valid = true;
            break;
        }
    }
    if(valid == false)
        return false;

    valid = true;
    for(int i=0;i<(int)pwd.size()-2;i++){
        string temp = pwd.substr(i,3);
        if(temp.size() < 3)
            break;

        bool prev = isVowel(temp[0]);
        for(int j=1;j<3;j++){
            if(prev != isVowel(temp[j]))
                break;
            if(j == 2)
                valid = false;
        }
    }
    if(valid == false)
        return false;

    valid = true;
    for(int i=0;i<(int)pwd.size()-1;i++){
        string temp = pwd.substr(i,2);
        if(temp.size() < 2)
            break;

        if(temp == "ee" || temp == "oo")
            continue;

        if(temp[0] == temp[1])
            valid = false;
    }

    return valid;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        string pwd;
        cin >> pwd;

        if(pwd == "end")
            break;

        cout << "<" << pwd << "> is ";
        if(!checkPwdValid(pwd))
            cout << "not ";
        cout << "acceptable." << '\n';
    }
    return 0;
}