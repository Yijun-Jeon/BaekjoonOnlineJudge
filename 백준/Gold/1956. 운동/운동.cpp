#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_V 400
#define MAX_DIST MAX_V*MAX_V*10000

using namespace std;

int V,E, result = MAX_DIST+1;
int dist[MAX_V+1];
vector<pair<int,int> > graph[MAX_V+1];

int dijkstra(int start){
    fill(&dist[0],&dist[V+1],MAX_DIST+1);

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d >= result)
            return MAX_DIST+1;
        
        if(cur == start && d > 0)
            return d;

        if(dist[cur] < d)
            continue;

        for(auto next: graph[cur]){
            if(next.second == start || d + next.first < dist[next.second]){
                dist[next.second] = d + next.first;
                pq.push(make_pair(-(d+next.first),next.second));
            }
        }
    }

    return MAX_DIST+1;
}

int main(void)
{
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        graph[a].push_back(make_pair(c,b));
    }

    for(int i=1;i<=V;i++)
        result = min(result,dijkstra(i));

    if(result == MAX_DIST+1)
        result = -1;
    printf("%d\n",result);
    return 0;
}