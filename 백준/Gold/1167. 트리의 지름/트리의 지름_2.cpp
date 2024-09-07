#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_V 100000

using namespace std;

int V;
bool visited[MAX_V+1];
vector<pair<int,int> > graph[MAX_V+1];

pair<int,int> BFS(int start){
    memset(visited,false,sizeof(visited));
    queue<pair<int,int> > q;
    q.push(make_pair(start,0));

    int maxV = start;
    int maxCost = 0;
    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(visited[cur])
            continue;

        visited[cur] = true;
        if(maxCost < cost){
            maxV = cur;
            maxCost = cost;
        }
        for(auto next: graph[cur]){
            if(!visited[next.first])
                q.push(make_pair(next.first,cost + next.second));
        }
    }

    return make_pair(maxV,maxCost);
}

int main(void)
{
    scanf("%d",&V);
    for(int v=0;v<V;v++){
        int start;
        scanf("%d",&start);

        while(true){
            int end;
            scanf("%d",&end);

            if(end == -1)
                break;

            int cost;
            scanf("%d",&cost);    

            graph[start].push_back(make_pair(end,cost));
        }
    }

    printf("%d\n",BFS(BFS(1).first).second);
    return 0;
}