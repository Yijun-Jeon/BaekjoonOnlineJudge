#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 500
#define MAX_DIST 2e9

using namespace std;

int N,M,W;
int dist[MAX_N+1];
vector<pair<pair<int,int>,int> > edges;

bool bellmanFord(){
    for(int n=1;n<N;n++){
        for(int i=0;i<edges.size();i++){
            int from = edges[i].first.first;
            int to = edges[i].first.second;
            int cost = edges[i].second;

            if(dist[to] > dist[from] + cost)
                dist[to] = dist[from]+cost;
        }
    }

    for(int i=0;i<edges.size();i++){
        int from = edges[i].first.first;
        int to = edges[i].first.second;
        int cost = edges[i].second;

        if(dist[to] > dist[from] + cost)
            return true;
    }

    return false;
}

void init(){
    edges.clear();
    fill(&dist[0],&dist[MAX_N+1],MAX_DIST);
}

int main(void)
{
    int TC;
    scanf("%d",&TC);

    for(int tc=0;tc<TC;tc++){
        scanf("%d %d %d",&N,&M,&W);
        init();

        for(int m=0;m<M;m++){
            int S,E,T;
            scanf("%d %d %d",&S,&E,&T);

            edges.push_back(make_pair(make_pair(S,E),T));
            edges.push_back(make_pair(make_pair(E,S),T));
        }

        for(int w=0;w<W;w++){
            int S,E,T;
            scanf("%d %d %d",&S,&E,&T);

            edges.push_back(make_pair(make_pair(S,E),-T));
        }

        if(bellmanFord()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}