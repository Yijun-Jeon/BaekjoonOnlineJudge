#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 300000
#define MAX_DIST 1e6

using namespace std;

int N,M,K,X;
vector<int> graph[MAX_N+1];
int dist[MAX_N+1];

void BFS(int start){
    queue<pair<int,int> > q;
    q.push(make_pair(start,0));

    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(dist[cur] != MAX_DIST)
            continue;
        dist[cur] = cost;

        for(int next: graph[cur]){
            if(dist[next] == MAX_DIST)
                q.push(make_pair(next,cost+1));
        }
    }
}

int main(void)
{
    scanf("%d %d %d %d",&N,&M,&K,&X);
    fill(&dist[0],&dist[N+1],MAX_DIST);
    for(int i=0;i<M;i++){
        int A,B;
        scanf("%d %d",&A,&B);

        graph[A].push_back(B);
    }

    BFS(X);

    vector<int> result;
    for(int i=1;i<=N;i++){
        if(dist[i] == K)
            result.push_back(i);
    }

    if(result.size() == 0)
        result.push_back(-1);

    for(int city: result)
        printf("%d\n",city);
    return 0;
}