#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S,bomb;
    cin >> S >> bomb;

    string result;
    for(int i=0;i<S.size();i++){
        result += S[i];
        if(S.size() < bomb.size())
            continue;

        bool isBomb = true;
        for(int j=0;j<bomb.size() && isBomb;j++){
            if(result[j+result.size()-bomb.size()] != bomb[j])
                isBomb = false;
        }

        if(isBomb) result.replace(result.size()-bomb.size(),bomb.size(),"");
    }

    if(result.empty()) cout << "FRULA" << '\n';
    else cout << result << '\n';
    return 0;
}