#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_N 500
#define MAX_DIST 1e9

using namespace std;

int N,M,W;
int dist[MAX_N+1];
vector<pair<int,pair<int,int> > > edges;

bool Bellman_Ford(){
    fill(&dist[0],&dist[N+1],MAX_DIST);
    
    dist[1] = 0;
    for(int i=1;i<N;i++){
        for(int j=0;j<edges.size();j++){
            int cost = edges[j].first;
            int from = edges[j].second.first;
            int to = edges[j].second.second;

            if(dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }
    }

    for(int i=0;i<edges.size();i++){
        int cost = edges[i].first;
        int from = edges[i].second.first;
        int to = edges[i].second.second;

        if(dist[to] > dist[from]+cost)
            return true;
    }
    return false;
}

int main(void)
{
    int TC;
    scanf("%d",&TC);

    for(int test_case=0;test_case<TC;test_case++){
        edges.clear();
        scanf("%d %d %d",&N,&M,&W);

        for(int m=0;m<M;m++){
            int S,E,T;
            scanf("%d %d %d",&S,&E,&T);

            edges.push_back(make_pair(T,make_pair(S,E)));
            edges.push_back(make_pair(T,make_pair(E,S)));
        }

        for(int w=0;w<W;w++){
            int S,E,T;
            scanf("%d %d %d",&S,&E,&T);

            edges.push_back(make_pair(-T,make_pair(S,E)));
        }

        if(Bellman_Ford()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}