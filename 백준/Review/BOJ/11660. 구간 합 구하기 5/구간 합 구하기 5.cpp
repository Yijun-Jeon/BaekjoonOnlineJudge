#include <iostream>

#define MAX_N 1024

using namespace std;

int map[MAX_N+1][MAX_N+1];
int dp[MAX_N+1][MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;   
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cin >> map[i][j];
    }

    for(int i=1;i<=N;i++){
        dp[1][i] = dp[1][i-1] + map[1][i];
        dp[i][1] = dp[i-1][1] + map[i][1];
    }

    for(int i=2;i<=N;i++){
        for(int j=2;j<=N;j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + map[i][j];
    }

    for(int i=0;i<M;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << result << '\n';
    }
    return 0;
}