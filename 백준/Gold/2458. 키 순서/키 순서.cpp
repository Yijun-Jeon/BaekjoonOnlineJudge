#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX_N 500
#define MAX_DIST 10000

using namespace std;

int graph[MAX_N+1][MAX_N+1];
int dist[MAX_N+1][MAX_N+1];

int main(void)
{
    int N,M;
    scanf("%d %d",&N,&M);

    fill(&dist[0][0],&dist[N][N+1],MAX_DIST);
    for(int i=1;i<=N;i++)
        dist[i][i] = 1;

    for(int i=0;i<M;i++){
        int A,B;
        scanf("%d %d",&A,&B);

        graph[B][A] = 1;
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(graph[i][j])
                    dist[i][j] = graph[i][j];
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    int result = 0;
    for(int i=1;i<=N;i++){
        int cnt = 0;
        for(int j=1;j<=N;j++){
            if(dist[i][j] == MAX_DIST && dist[j][i] == MAX_DIST)
                continue;
            cnt++;
        }
        if(cnt == N)
            result++;
    }
    printf("%d\n",result);
    return 0;
}