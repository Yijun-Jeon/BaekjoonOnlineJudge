#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 500

using namespace std;

int n,m;
int rankToTeam[MAX_N+1];
int teamToRank[MAX_N+1];
int indegree[MAX_N+1];
vector<int> graph[MAX_N+1];

int main(void)
{  
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int TC;
    cin >> TC;

    while(TC--){
        cin >> n;

        for(int i=1;i<=n;i++)
            graph[i].clear();

        for(int i=1;i<=n;i++){
            cin >> rankToTeam[i];            

            teamToRank[rankToTeam[i]] = i;
            indegree[rankToTeam[i]] = i-1;
            for(int j=0;j<i;j++)
                graph[rankToTeam[j]].push_back(rankToTeam[i]);
        }

        cin >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;

            if(teamToRank[a] > teamToRank[b])
                swap(a,b);

            graph[b].push_back(a); indegree[b]--;
            graph[a].erase(find(graph[a].begin(),graph[a].end(),b)); indegree[a]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        
        int rank = 1;
        int result[n+1];
        bool uncertain = false;
        while(!q.empty()){
            if(q.size() > 1){
                uncertain = true;
                break;
            }

            int cur = q.front();
            q.pop();

            result[rank++] = cur;
            for(int next: graph[cur]){
                if(--indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        if(uncertain){
            cout << "?" << '\n';
        }else if(rank < n){
            cout << "IMPOSSIBLE" << '\n';
        }else{
            for(int i=1;i<=n;i++)
                cout << result[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}