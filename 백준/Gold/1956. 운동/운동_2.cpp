#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_V 400
#define MAX_DIST MAX_V*10000

using namespace std;

int main(void)
{
    int V,E;
    scanf("%d %d",&V,&E);

    int dist[V+1][V+1];
    fill(&dist[0][0],&dist[V][V+1],MAX_DIST+1);

    for(int i=0;i<E;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        dist[a][b] = c;
    }

    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    int result = MAX_DIST+1;
    for(int i=1;i<=V;i++)
        result = min(result,dist[i][i]);

    if(result == MAX_DIST+1)
        result = -1;
    printf("%d\n",result);
    return 0;
}