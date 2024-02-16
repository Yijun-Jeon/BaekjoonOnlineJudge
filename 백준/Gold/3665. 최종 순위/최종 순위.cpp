#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_N 500

using namespace std;

int indegree[MAX_N+1];
int graph[MAX_N+1][MAX_N+1];
int n;

void init(){
    memset(indegree,0,sizeof(indegree));
    memset(graph,0,sizeof(graph));
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case = 0; test_case < T; test_case++){
        init();
        
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int team;
            scanf("%d",&team);

            indegree[team] = i-1;
            for(int j=1;j<=n;j++){
                if(team == j)
                    continue;
                if(graph[j][team] == 0)
                    graph[team][j] = 1;
            }
        }

        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);

            if(graph[b][a] == 1)
                swap(a,b);

            indegree[a]++;
            indegree[b]--;

            graph[a][b] = 0;
            graph[b][a] = 1;
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> score;
        bool isVague = false;
        while(!q.empty()){
            if(q.size() > 1){
                isVague = true;
                break;
            }

            int cur = q.front();
            q.pop();
            score.push_back(cur);

            for(int i=1;i<=n;i++){
                if(graph[cur][i]){
                    if(--indegree[i] == 0)
                        q.push(i);
                }
            }
        }
        
        if(isVague)
            printf("?\n");
        else if(score.size() < n)
            printf("IMPOSSIBLE\n");
        else{
            for(int i=0;i<n;i++)
                printf("%d ",score[i]);
            printf("\n");
        }
    }

    return 0;
}