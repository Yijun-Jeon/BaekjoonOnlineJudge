#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string A,B;
    getline(cin,A);
    getline(cin,B);

    int pattern[B.size()];
    pattern[0] = 0;

    for(int i=1,j=0;i<B.size();i++){
        while(j > 0 && B[i] != B[j])
            j = pattern[j-1];

        if(B[i] == B[j]) ++j;
        pattern[i] = j;
    }

    int result = 0;
    vector<int> idxVec;
    for(int i=0,j=0;i<A.size();i++){
        while(j > 0 && A[i] != B[j])
            j = pattern[j-1];

        if(A[i] == B[j]) j++;

        if(j == B.size()){
            result++;
            idxVec.push_back(i-B.size()+2);
        }
    }

    cout << result << '\n';
    for(int i=0;i<idxVec.size();i++)
        cout << idxVec[i] << " ";
    cout << '\n';        
    return 0;
}