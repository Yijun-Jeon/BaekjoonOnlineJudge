#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S;
    while(true){
        cin >> S;
        if(S == ".")
            break;

        int pattern[S.size()];
        pattern[0] = 0;
        for(int i=0,j=1;j<S.size();j++){
            while(i>0 && S[i] != S[j])
                i = pattern[i-1];
            
            if(S[i] == S[j]) i++;
            pattern[j] = i;
        }     

        string P;
        for(int i=0;i<S.size()-pattern[S.size()-1];i++)
            P += S[i];

        int cnt = 0;
        bool valid = true;
        for(int i=0;i<S.size() && valid;i += P.size()){
            for(int j=0;j<P.size();j++){
                if(S[i+j] != P[j]){
                    valid = false;
                    break;
                }
            }
            cnt++;
        }
        
        if(valid == false)
            printf("1\n");
        else
            printf("%d\n",cnt);
    }
    return 0;
}