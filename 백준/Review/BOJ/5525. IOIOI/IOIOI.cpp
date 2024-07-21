#include <iostream>
#include <string>
#include <vector>

#define MAX_N 1000000

using namespace std;

int N,M;

vector<int> makeTable(string P){
    vector<int> pattern(P.size(),0);

    int j=0;
    for(int i=1;i<P.size();i++){
        while(j>0 && P[i] != P[j])
            j = pattern[j-1];
        
        if(P[i] == P[j])
            pattern[i] = ++j;
    }
    return pattern;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    string S;
    cin >> S;

    string P = "I";
    for(int i=0;i<N;i++)
        P += "OI";

    vector<int> pattern = makeTable(P);
    
    int j= 0;
    int result = 0;
    for(int i=0;i<S.size();i++){
        while(j>0 && S[i] != P[j])
            j = pattern[j-1];
        
        if(S[i] == P[j]){
            if(j == pattern.size()-1){
                result++;
                j = pattern[j];
            }
            else j++;
        }
    }    
    cout << result << '\n';
    return 0;
}