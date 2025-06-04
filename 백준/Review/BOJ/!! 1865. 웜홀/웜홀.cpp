#include <stdio.h>
#include <algorithm>

#define MAX_N 500
#define MAX_DIST 1e9

using namespace std;

int N,M,W;
int dist[MAX_N+1][MAX_N+1];

bool floyd(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);

                if(dist[i][i] < 0)
                    return true;
            }
        }
    }

    return false;
}

int main(void)
{
    int TC;
    scanf("%d",&TC);

    for(int test_case=0;test_case<TC;test_case++){
        fill(&dist[0][0],&dist[MAX_N][MAX_N+1],MAX_DIST);

        scanf("%d %d %d",&N,&M,&W);

        for(int m=0;m<M;m++){
            int S,E,T;
            scanf("%d %d %d",&S,&E,&T);

            dist[S][E] = min(dist[S][E],T);
            dist[E][S] = min(dist[E][S],T);
        }

        for(int w=0;w<W;w++){
            int S,E,T;
            scanf("%d %d %d",&S,&E,&T);

            dist[S][E] = min(dist[S][E],-T);
        }

        if(floyd()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}