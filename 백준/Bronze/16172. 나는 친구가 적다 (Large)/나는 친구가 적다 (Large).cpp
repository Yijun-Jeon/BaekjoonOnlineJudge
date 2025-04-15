#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    string S,K;
    cin >> S >> K;

    string base;
    for(int i=0;i<S.size();i++){
        if(!isdigit(S[i]))
            base += S[i];
    }

    int pattern[K.size()];
    pattern[0] = 0;

    for(int i=1,j=0;i<K.size();i++){
        while(j>0 && K[i] != K[j])
            j = pattern[j-1];
        
        if(K[i] == K[j]) j++;
        pattern[i] = j;
    }

    for(int i=0,j=0;i<base.size();i++){
        while(j>0 && base[i] != K[j])
            j = pattern[j-1];

        if(base[i] == K[j]) j++;
        
        if(j == K.size()){
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}