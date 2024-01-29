#include <stdio.h>
#include <algorithm>

#define MAX_N 100
#define MAX_DIST 1e7

using namespace std;

int n,m;
int dist[MAX_N+1][MAX_N+1];

int main(void)
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,cost;
        scanf("%d %d %d",&a,&b,&cost);

        if(dist[a][b] != 0 && dist[a][b] < cost)
            continue;
        dist[a][b] = cost;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j)
                dist[i][j] = 0;
            else if(dist[i][j] == 0)
                dist[i][j] = MAX_DIST;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == MAX_DIST)
                dist[i][j] = 0;
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}