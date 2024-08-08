#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

int N,M;
vector<pair<int,int> > graph[MAX_N+1];
bool visited[MAX_N+1];

int dijkstra(int start, int end){
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == end)
            return cost;

        if(visited[cur])
            continue;
        visited[cur] = true;

        for(pair<int,int> next: graph[cur]){
            if(!visited[next.first])
                pq.push(make_pair(-(cost + next.second),next.first));
        }
    }
    return -1;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b,cost;
        scanf("%d %d %d",&a,&b,&cost);

        graph[a].push_back(make_pair(b,cost));
    }

    int A,B;
    scanf("%d %d",&A,&B);

    printf("%d\n",dijkstra(A,B));
    return 0;
}