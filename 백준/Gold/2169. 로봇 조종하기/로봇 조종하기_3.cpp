#include <iostream>
#include <algorithm>

#define MAX_N 1000
#define MIN_DIST -10001

using namespace std;

int N,M;
int dp[2][MAX_N][4]; // 원본, 상하, 좌우, 우좌

int map[MAX_N][MAX_N];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    fill(&dp[0][0][0],&dp[1][M-1][4],MIN_DIST);

    dp[0][0][1] = map[0][0];

    // 첫째줄 초기화
    for(int j=1;j<M;j++)
        dp[0][j][1] = dp[0][j-1][1] + map[0][j];

    // 둘째줄부터 반복
    for(int i=1;i<N;i++){
        // 위 -> 아래
        for(int j=0;j<M;j++)
            dp[i%2][j][1] = max(dp[(i-1)%2][j][1],max(dp[(i-1)%2][j][2],dp[(i-1)%2][j][3])) + map[i][j];

        // 좌 -> 우
        dp[i%2][0][2] = dp[i%2][0][1];
        for(int j=1;j<M;j++)
            dp[i%2][j][2] = max(dp[i%2][j-1][1],dp[i%2][j-1][2]) + map[i][j];

        // 우 -> 좌 
        dp[i%2][M-1][3] = dp[i%2][M-1][1];
        for(int j=M-2;j>=0;j--)
            dp[i%2][j][3] = max(dp[i%2][j+1][1],dp[i%2][j+1][3]) + map[i][j];
    }

    cout << max(dp[(N-1)%2][M-1][1],max(dp[(N-1)%2][M-1][2],dp[(N-1)%2][M-1][3])) << '\n';
    return 0;
}