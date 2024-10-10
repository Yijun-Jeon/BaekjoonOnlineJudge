#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAX_N 10000
#define MAX_K 14

using namespace std;

int N;
int depth[MAX_N+1];
int parents[MAX_K+1][MAX_N+1];
vector<int> graph[MAX_N+1];

void BFS(int start){
    memset(depth,0,sizeof(depth));
    queue<pair<int,int> > q;
    q.push(make_pair(1,start));

    while(!q.empty()){
        int d = q.front().first;
        int cur = q.front().second;
        q.pop();

        depth[cur] = d;

        for(int k=1;k<=MAX_K;k++)
            parents[k][cur] = parents[k-1][parents[k-1][cur]];

        for(int next: graph[cur]){
            if(depth[next] == 0){
                depth[next] = d+1;
                q.push(make_pair(d+1,next));
            }
        }
    }
}

int LCA(int a, int b){
    if(depth[a] > depth[b])
        swap(a,b);

    for(int k=MAX_K;k>=0;k--){
        if(pow(2,k) <= depth[b] - depth[a])
            b = parents[k][b];
    }

    if(a == b)
        return a;

    for(int k=MAX_K;k>=0;k--){
        if(parents[k][a] != parents[k][b]){
            a = parents[k][a];
            b = parents[k][b];
        }
    }

    if(a != b)
        a = parents[0][a];

    return a;
}

void init(){
    for(int i=0;i<=MAX_N;i++)
        graph[i].clear();

    memset(depth,0,sizeof(depth));
    memset(parents,0,sizeof(parents));
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        init();

        scanf("%d",&N);

        int a,b;
        for(int n=0;n<N-1;n++){
            scanf("%d %d",&a,&b);

            parents[0][b] = a;
            graph[a].push_back(b);
        }

        for(int i=1;i<=N;i++){
            if(parents[0][i] == 0){
                BFS(i);
                break;
            }
        }

        scanf("%d %d",&a,&b);
        printf("%d\n",LCA(a,b));
    }  
    return 0;
}