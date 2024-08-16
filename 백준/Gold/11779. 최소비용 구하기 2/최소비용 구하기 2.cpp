#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 1000
#define MAX_DIST 1e9

using namespace std;

int n,m;
int dist[MAX_N+1];
int pre[MAX_N+1];
vector<pair<int,int> > graph[MAX_N+1];

void dijkstra(int start, int end){
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(start,start)));

    while(!pq.empty()){
        int curDist = -pq.top().first;
        int curPos = pq.top().second.first;
        int prePos = pq.top().second.second;
        pq.pop();

        if(dist[curPos] <= curDist)
            continue;

        dist[curPos] = curDist;
        pre[curPos] = prePos;

        if(curPos == end)
            return;

        for(auto next: graph[curPos]){
            if(dist[next.first] > curDist+next.second)
                pq.push(make_pair(-(curDist+next.second),make_pair(next.first,curPos)));
        }
    }
}

int main(void)
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int start,end,cost;
        scanf("%d %d %d",&start,&end,&cost);

        graph[start].push_back(make_pair(end,cost));
    }

    fill(&dist[0],&dist[n+1],MAX_DIST);

    int start,end;
    scanf("%d %d",&start,&end);

    dijkstra(start,end);

    vector<int> paths;
    for(int path=end; path != start; path = pre[path])
        paths.push_back(path);
    paths.push_back(start);

    printf("%d\n%d\n",dist[end],(int)paths.size());
    for(int i=paths.size()-1;i>=0;i--)
        printf("%d ",paths[i]);
    printf("\n");
    return 0;
}