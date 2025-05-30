#include <iostream>
#include <algorithm>

#define MAX_N 10

using namespace std;

int N, result = 1e9;
bool visited[MAX_N+1];
int dist[MAX_N+1][MAX_N+1];

void DFS(int start, int cur, int cnt, int sum){
    visited[cur] = true;
    if(start == cur && cnt == N+1){
        result = min(result,sum);
        return;
    }

    for(int i=1;i<=N;i++){
        if(dist[cur][i] == 0)
            continue;
        if((i == start && cnt == N) || visited[i] == false)
            DFS(start,i,cnt+1,sum + dist[cur][i]);
    }
    visited[cur] = false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cin >> dist[i][j];
    }

    for(int i=1;i<=N;i++)
        DFS(i,i,1,0);

    cout << result << '\n';
    return 0;
}