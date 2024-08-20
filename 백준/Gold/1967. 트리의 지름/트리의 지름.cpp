#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_N 10000

using namespace std;


int n;
int result = 0;
bool visited[MAX_N+1];
vector<pair<int,int> > graph[MAX_N+1];

void dijkstra(int start){
    memset(visited,false,sizeof(visited));

    queue<pair<int,int> > q;
    q.push(make_pair(start,0));

    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(visited[cur])
            continue;
        visited[cur] = true;
        result = max(result,cost);

        for(auto next: graph[cur]){
            if(visited[next.first] == false)
                q.push(make_pair(next.first,cost+next.second));
        }
    }
}

int main(void)
{
    scanf("%d",&n);

    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    printf("%d\n",result);
    return 0;
}