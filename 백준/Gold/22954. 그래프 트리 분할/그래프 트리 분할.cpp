#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_N 100000

using namespace std;

int N,M;
int parents[MAX_N+1];

pair<int,int> lastEdge;
vector<pair<int,int> > graph[MAX_N+1];

int startNodes[2];
vector<int> tree[2];

void BFS(int start, int order){
    queue<pair<int,int> > q;
    q.push(make_pair(start,-1));
    parents[start] = start;

    while(!q.empty()){
        int cur = q.front().first;
        int edgeNum = q.front().second;
        q.pop();

        if(cur != start)
            tree[order].push_back(edgeNum);            

        for(auto next: graph[cur]){
            if(parents[next.first] == 0){
                parents[next.first] = start;
                q.push(next);
                lastEdge = next;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d",&N,&M);

    for(int i=1;i<=M;i++){
        int u,v;
        scanf("%d %d",&u,&v);

        graph[u].push_back(make_pair(v,i));
        graph[v].push_back(make_pair(u,i));
    }

    if(N <= 2){
        printf("-1\n");
        return 0;
    }

    int graphCnt = 0;
    for(int i=1;i<=N;i++){
        if(parents[i] == 0){
            if(graphCnt == 2){
                printf("-1\n");
                return 0;
            }

            startNodes[graphCnt] = i;
            BFS(i,graphCnt);
            graphCnt++;
        }
    }

    if(graphCnt == 2 && tree[0].size() == tree[1].size()){
        printf("-1\n");
        return 0;
    }

    if(graphCnt == 1){
        tree[0].pop_back();
        startNodes[1] = lastEdge.first;
        parents[lastEdge.first] = lastEdge.first;
    }

    printf("%d %d\n",(int)tree[0].size()+1,(int)tree[1].size()+1);
    
    for(int i=1;i<=N;i++){
        if(parents[i] == startNodes[0])
            printf("%d ",i);
    }
    printf("\n");
    
    for(int edge: tree[0])
        printf("%d ",edge);
    printf("\n");

    for(int i=1;i<=N;i++){
        if(parents[i] == startNodes[1])
            printf("%d ",i);
    }
    printf("\n");

    for(int edge: tree[1])
        printf("%d ",edge);
    printf("\n");
    return 0;
}