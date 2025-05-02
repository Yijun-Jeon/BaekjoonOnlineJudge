#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define MAX_DIST 1e7

using namespace std;

int N,M;
int dist[MAX_N+1][MAX_N+1];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        cin >> N >> M;

        fill(&dist[0][0],&dist[N][N+1],MAX_DIST);

        for(int i=0;i<M;i++){
            int a,b,c;
            cin >> a >> b >> c;

            dist[a][b] = c;
            dist[b][a] = c;
        }

        int K;
        cin >> K;

        vector<int> rooms(K);
        for(int i=0;i<K;i++)
            cin >> rooms[i];

        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(i == j) dist[i][j] = 0;
                    else dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int minDist = MAX_DIST, result;
        for(int i=1;i<=N;i++){
            int sum = 0;
            for(int room: rooms)
                sum += dist[i][room];

            if(sum < minDist){
                minDist = sum;
                result = i;
            }
        }

        cout << result << '\n';
    }
    return 0;
}