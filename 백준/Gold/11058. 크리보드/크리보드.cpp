#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    long long dp[N+1];
    dp[0] = 0;
    for(int i=1;i<=N;i++){
        dp[i] = dp[i-1] + 1;

        for(int j=i-3;j>0;j--){
            dp[i] = max(dp[i],dp[j] * (i-1-j));
        }
    }
    cout << dp[N] << '\n';
    return 0;
}