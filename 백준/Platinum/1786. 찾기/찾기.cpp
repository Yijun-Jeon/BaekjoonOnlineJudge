#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string T,P;
    getline(cin,T);
    getline(cin,P);

    int pattern[P.size()];
    pattern[0] = 0;
    for(int i=0,j=1;j<P.size();j++){
        while(i>0 && P[i] != P[j])
            i = pattern[i-1];
        
        if(P[i] == P[j]) i++;
        pattern[j] = i;
    }

    vector<int> result;
    for(int i=0,j=0;j<T.size();j++){
        while(i>0 && P[i] != T[j])
            i = pattern[i-1];
        
        if(P[i] == T[j]) i++;
        if(i == P.size())
            result.push_back(j+2-P.size());
    }    
    
    cout << result.size() << '\n';
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << '\n';
    return 0;
}