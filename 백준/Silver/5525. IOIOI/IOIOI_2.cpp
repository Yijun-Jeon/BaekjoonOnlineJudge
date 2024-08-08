#include <iostream>
#include <string>

#define MAX_N 1000000

using namespace std;

int pattern[MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    string S;
    cin >> S;

    string P = "I";
    while(N--) P += "OI";

    int j=0;
    for(int i=1;i<P.size();i++){
        while(j>0 && P[i] != P[j])
            j = pattern[j-1];
        if(P[i] == P[j])
            j++;
        pattern[i] = j;
    }

    j=0;
    int result = 0;
    for(int i=0;i<S.size();i++){
        while(j>0 && S[i] != P[j])
            j = pattern[j-1];
        if(S[i] == P[j])
            j++;
        if(j == P.size()){
            result++;
            j = pattern[j-1];
        }
    }

    cout << result << '\n';
    return 0;
}