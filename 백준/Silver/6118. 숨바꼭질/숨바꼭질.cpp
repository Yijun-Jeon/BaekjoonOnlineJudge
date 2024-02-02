#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 20000
#define MAX_DIST 50000

using namespace std;

int N,M;
vector<int> graph[MAX_N+1];
int dist[MAX_N+1];

int dijkstra(){
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,1));

    int maxDist = 0;
    while(!pq.empty()){
        int curDist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < MAX_DIST)
            continue;

        dist[now] = curDist;
        maxDist = max(maxDist,curDist);
        for(int next: graph[now]){
            if(dist[next] > curDist+1)
                pq.push(make_pair(-curDist-1,next));
        }
    }
    return maxDist;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int A,B;
        scanf("%d %d",&A,&B);

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    fill(&dist[0],&dist[N+1],MAX_DIST);

    int maxDist = dijkstra();
    int hide = 0;
    int same = 0;
    for(int i=1;i<=N;i++){
        if(dist[i] == maxDist){
            if(hide == 0)
                hide = i;
            same++;
        }
    }

    printf("%d %d %d\n",hide,maxDist,same);
    return 0;
}