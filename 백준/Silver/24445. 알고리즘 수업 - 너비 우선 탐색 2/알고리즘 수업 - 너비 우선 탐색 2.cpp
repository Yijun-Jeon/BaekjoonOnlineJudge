#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 100000
using namespace std;

bool visited[MAX_N+1];
int orders[MAX_N+1];
int order = 1;

void bsf(vector<int> graph[], int start){
    queue<int> Q;
    
    Q.push(start);
    while(!Q.empty()){
        int here = Q.front();
        Q.pop();

        if(visited[here])
            continue;

        orders[here] = order++;
        visited[here] = true;

        for(int i=0;i<graph[here].size();i++){
            int next = graph[here][i];
            if(visited[next] == false)
                Q.push(next);
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,R;
    cin >> N >> M >> R;

    vector<int> graph[N+1];

    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=N;i++)
        sort(graph[i].begin(),graph[i].end(),greater<int>());

    bsf(graph,R);
    for(int i=1;i<=N;i++)
        cout << orders[i] << '\n';
    return 0;
}