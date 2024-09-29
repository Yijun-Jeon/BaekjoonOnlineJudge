#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_N 500
#define MAX_M 6000
#define MAX_DIST 60000001

using namespace std;

int N,M;
long long dist[MAX_N+1];
vector<pair<pair<int,int>,int> > edges(MAX_M);

void BellmanFord(int start){
    dist[start] = 0;
    for(int n=1;n<N;n++){
        for(int m=0;m<M;m++){
            int from = edges[m].first.first;
            int to = edges[m].first.second;
            int cost = edges[m].second;

            if(dist[from] == MAX_DIST)
                continue;

            if(dist[from] + cost < dist[to])
                dist[to] = dist[from] + cost;
        }
    }

    for(int m=0;m<M;m++){
        int from = edges[m].first.first;
        int to = edges[m].first.second;
        int cost = edges[m].second;

        if(dist[from] == MAX_DIST)
            continue;

        if(dist[from] + cost < dist[to]){
            printf("-1\n");
            return;
        }
    }

    for(int n=2;n<=N;n++){
        if(dist[n] == MAX_DIST)
            dist[n] = -1;
        printf("%lld\n",dist[n]);
    }
}

int main(void)
{
    scanf("%d %d",&N,&M);
    fill(&dist[0],&dist[MAX_N+1],MAX_DIST);
    
    for(int m=0;m<M;m++)
        scanf("%d %d %d",&edges[m].first.first,&edges[m].first.second,&edges[m].second);

    BellmanFord(1);
    return 0;
}