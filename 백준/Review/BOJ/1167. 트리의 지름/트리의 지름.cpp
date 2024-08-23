#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_V 100000

using namespace std;

int V;
bool visited[MAX_V+1];
vector<pair<int,int> > graph[MAX_V+1];

pair<int,int> dijkstra(int start){
    memset(visited,false,sizeof(visited));

    queue<pair<int,int> > q;
    q.push(make_pair(start,0));

    pair<int,int> result = make_pair(start,0);
    while(!q.empty()){
        int node = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(visited[node])
            continue;
        
        visited[node] = true;
        if(result.second < cost)    
            result = make_pair(node,cost);
        for(auto next: graph[node]){
            if(visited[next.first] == false)
                q.push(make_pair(next.first,cost+next.second));
        }
    }
    return result;
}

int main(void)
{
    scanf("%d",&V);
    for(int i=0;i<V;i++){
        int from;
        scanf("%d",&from);

        while(true){
            int to,cost;
            scanf("%d",&to);
            
            if(to == -1)
                break;

            scanf("%d",&cost);

            graph[from].push_back(make_pair(to,cost));
        }
    }

    printf("%d\n",dijkstra(dijkstra(1).first).second);
    return 0;
}