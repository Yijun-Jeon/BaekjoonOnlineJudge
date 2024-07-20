#include <stdio.h>
#include <algorithm>

#define MAX_N 100
#define MAX_DIST 1e9

using namespace std;

int N,M;
int dist[MAX_N+1][MAX_N+1];

int main(void)
{
    scanf("%d %d",&N,&M);

    fill(&dist[0][0],&dist[MAX_N][MAX_N+1],MAX_DIST);
    for(int i=0;i<M;i++){
        int A,B;
        scanf("%d %d",&A,&B);

        dist[A][B] = 1;
        dist[B][A] = 1;
    }

    for(int i=1;i<=N;i++)
        dist[i][i] = 0;

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    pair<int,int> result = make_pair(MAX_DIST,-1);
    for(int i=1;i<=N;i++){
        int kv = 0;
        for(int j=1;j<=N;j++)
            kv += dist[i][j];

        if(kv < result.first)
            result = make_pair(kv,i);
    }
    printf("%d\n",result.second);
    return 0;
}