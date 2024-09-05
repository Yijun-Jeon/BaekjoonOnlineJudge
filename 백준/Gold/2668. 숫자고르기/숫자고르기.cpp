#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_M 100

using namespace std;

int graph[MAX_M+1];
bool selected[MAX_M+1];
bool visited[MAX_M+1];

bool BFS(int start){
    memset(visited,false,sizeof(visited));

    int cur = start;
    while(visited[cur] == false){
        visited[cur] = true;
        cur = graph[cur];
        if(cur == start)
            return true;
    }
    return false;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
        scanf("%d",&graph[i]);


    queue<int> q;
    for(int i=1;i<=N;i++){
        if(selected[i])
            continue;

        memset(visited,false,sizeof(visited));

        if(BFS(i)){
            selected[i] = true;
            q.push(i);
        }
    }
    printf("%d\n",(int)q.size());
    while(!q.empty()){
        printf("%d\n",q.front());
        q.pop();
    }
    return 0;
}