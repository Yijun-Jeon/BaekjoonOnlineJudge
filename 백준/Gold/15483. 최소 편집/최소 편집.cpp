#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int dp[MAX_N+1][MAX_N+1];

int main(void)
{
    string A,B;
    cin >> A >> B;

    for(int i=0;i<=B.size();i++)
        dp[0][i] = i;
    for(int i=0;i<=A.size();i++)
        dp[i][0] = i;

    for(int i=1;i<=A.size();i++){
        for(int j=1;j<=B.size();j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
        }
    }
    cout << dp[A.size()][B.size()] << '\n';
    return 0;
}