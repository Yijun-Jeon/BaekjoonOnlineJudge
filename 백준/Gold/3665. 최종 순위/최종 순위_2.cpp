#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 500

using namespace std;

int n,m;
int indegree[MAX_N+1];
vector<int> graph[MAX_N+1];
int rank2Team[MAX_N+1];
int team2Rank[MAX_N+1];

void init(int n){
    for(int i=0;i<=n;i++){
        indegree[i] = 0;
        graph[i].clear();
        rank2Team[i] = 0;
        team2Rank[i] = 0;
    }
}

void swapRank(int a,int b){
    if(team2Rank[b] < team2Rank[a])
        swap(a,b);

    for(auto iter = graph[a].begin(); iter != graph[a].end(); iter++){
        if(*iter == b){
            graph[a].erase(iter);
            break;
        }
    }
    indegree[b]--;

    graph[b].push_back(a);
    indegree[a]++;
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int test_case=0; test_case<T; test_case++){
        scanf("%d",&n);

        init(n);

        for(int i=1;i<=n;i++){
            int team;
            scanf("%d",&team);
            
            rank2Team[i] = team;
            team2Rank[team] = i;
            indegree[team] = i-1;
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                graph[rank2Team[i]].push_back(rank2Team[j]);
            }
        }

        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);

            swapRank(a,b);
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        bool ambiguous = false;
        while(!q.empty()){
            if(q.size() > 1){
                ambiguous = true;
                break;
            }

            int cur = q.front();
            q.pop();

            result.push_back(cur);

            for(int next : graph[cur]){
                if(--indegree[next] == 0)
                    q.push(next);
            }
        }

        if(ambiguous)
            printf("?\n");
        else if(result.size() < n)
            printf("IMPOSSIBLE\n");
        else{
            for(int team: result)
                printf("%d ",team);
            printf("\n");
        }
    }
    return 0;
}