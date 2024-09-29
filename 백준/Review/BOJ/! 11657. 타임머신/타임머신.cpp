#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 500
#define MAX_DIST 60000001

using namespace std;

int N,M;
long long dist[MAX_N+1];
vector<pair<long long,pair<int,int> > > edges;

bool BellmanFord(){
    fill(&dist[0],&dist[N+1],MAX_DIST);

    dist[1] = 0;
    for(int i=1;i<N;i++){
        for(int j=0;j<edges.size();j++){
            long long cost = edges[j].first;
            int from = edges[j].second.first;
            int to = edges[j].second.second;

            if(dist[from] == MAX_DIST) continue;

            if(dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }
    }

    for(int j=0;j<edges.size();j++){
        long long cost = edges[j].first;
        int from = edges[j].second.first;
        int to = edges[j].second.second;

        if(dist[from] == MAX_DIST) continue;

        if(dist[to] > dist[from] + cost)
            return true;
    }
    return false;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    
    for(int i=0;i<M;i++){
        int A,B,C;
        scanf("%d %d %d",&A,&B,&C);

        edges.push_back(make_pair(C,make_pair(A,B)));
    }

    if(BellmanFord()) printf("-1\n");
    else{
        for(int i=2;i<=N;i++){
            if(dist[i] == MAX_DIST)
                dist[i] = -1;
            printf("%lld\n",dist[i]);
        }
    }
    return 0;
}