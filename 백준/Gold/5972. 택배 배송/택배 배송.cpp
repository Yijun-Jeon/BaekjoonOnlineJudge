#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int N,M;
vector<pair<int,int> > graph[MAX_N+1];
bool visited[MAX_N+1];

int BFS(int start){
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == N)
            return cost;

        if(visited[cur])
            continue;

        visited[cur] = true;
        for(auto next: graph[cur]){
            if(visited[next.first] == false)
                pq.push(make_pair(-(cost+next.second),next.first));
        }
    }
    return -1;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int A,B,C;
        scanf("%d %d %d",&A,&B,&C);

        bool valid = true;
        for(int j=0;j<graph[A].size();j++){
            if(graph[A][j].second == B && graph[A][j].first < C){
                valid = false;
                break;
            }
        }
        if(valid){
            graph[A].push_back(make_pair(B,C));
            graph[B].push_back(make_pair(A,C));
        }   
    }

    printf("%d\n",BFS(1));
    return 0;
}