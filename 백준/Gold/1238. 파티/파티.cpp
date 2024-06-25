#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 1000
#define MAX_DIST 1000000

using namespace std;

int N,M,X;
vector<pair<int,int> > graph[MAX_N+1];
int dist[MAX_N+1];

int dijkstra(int start,int end){
    fill(&dist[0],&dist[MAX_N+1],MAX_DIST);

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == end)
            return curDist;

        if(dist[cur] <= curDist)
            continue;

        dist[cur] = curDist;
        for(auto next: graph[cur]){
            if(dist[next.first] > curDist + next.second)
                pq.push(make_pair(-(curDist + next.second),next.first));
        }
    }

    return -1;
}

int main(void)
{
    scanf("%d %d %d",&N,&M,&X);
    for(int i=0;i<M;i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);

        graph[a].push_back(make_pair(b,t));
    }

    int result = 0;
    for(int i=1;i<=N;i++)
        result = max(result,dijkstra(i,X) + dijkstra(X,i));
    printf("%d\n",result);
    return 0;
}