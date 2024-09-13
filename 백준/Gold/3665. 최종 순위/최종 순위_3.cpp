#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 500

using namespace std;

int N,M;
int indegree[MAX_N+1];
int rankToTeam[MAX_N+1];
vector<int> graph[MAX_N+1];

void init(){
    for(int i=0;i<=MAX_N;i++){
        indegree[i] = 0;
        graph[i].clear();
    }
}

void swapRank(int a, int b){
    if(find(graph[a].begin(),graph[a].end(),b) == graph[a].end())
        swap(a,b);

    indegree[a]++;
    indegree[b]--;
    graph[b].push_back(a);
    graph[a].erase(find(graph[a].begin(),graph[a].end(),b));
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        init();

        scanf("%d",&N);

        for(int n=1;n<=N;n++){
            scanf("%d",&rankToTeam[n]);
            indegree[rankToTeam[n]] = n-1;
        }

        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++)
                graph[rankToTeam[i]].push_back(rankToTeam[j]);
        }

        scanf("%d",&M);
        for(int m=1;m<=M;m++){
            int a,b;
            scanf("%d %d",&a,&b);

            swapRank(a,b);
        }

        queue<int> q;
        for(int n=1;n<=N;n++){
            if(indegree[n] == 0)
                q.push(n);
        }

        bool isAmbiguous = false;
        vector<int> result;
        while(!q.empty()){
            if(q.size() > 2){
                isAmbiguous = true;
                break;
            }
            int cur = q.front();
            q.pop();

            result.push_back(cur);
            for(int next: graph[cur]){
                if(--indegree[next] == 0)
                    q.push(next);   
            }
        }

        if(isAmbiguous)
            printf("?\n");
        else if(result.size() < N)
            printf("IMPOSSIBLE\n");
        else{
            for(int i=0;i<N;i++)
                printf("%d ",result[i]);
            printf("\n");
        }
    }
    return 0;
}