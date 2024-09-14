#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    string P = "I";

    for(int n=0;n<N;n++)
        P += "OI";

    int pattern[P.size()];
    pattern[0] = 0;
    for(int i=0,j=1;j<P.size();j++){
        while(i>0 && P[i] != P[j])
            i = pattern[i-1];

        if(P[i] == P[j]) i++;
        pattern[j] = i;
    }
    cin >> N;

    string S;
    cin >> S;

    int result=0;
    for(int j=0,i=0;j<S.size();j++){
        while(i>0 && P[i] != S[j])
            i = pattern[i-1];

        if(P[i] == S[j])
            i++;

        if(i == P.size())
            result++;
    }

    cout << result << '\n';
    return 0;
}