#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int dp[MAX_N+1][MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string A,B;
    cin >> A >> B;

    
    for(int i=1;i<=A.size();i++){
        for(int j=1;j<=B.size();j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            dp[i][j] = max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
        }
    }

    string lcs;
    int i = A.size(), j = B.size();
    int size = dp[A.size()][B.size()];
    while(size){
        if(dp[i-1][j] == size)
            i--;
        else if(dp[i][j-1] == size)
            j--;
        else{
            i--,j--,size--;
            lcs += A[i];
        }
    }

    cout << lcs.size() << '\n';

    reverse(lcs.begin(),lcs.end());
    if(!lcs.empty())
        cout << lcs << '\n';
    return 0;
}