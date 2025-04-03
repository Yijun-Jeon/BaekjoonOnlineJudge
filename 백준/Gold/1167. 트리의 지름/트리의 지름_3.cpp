#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_V 100000
#define MAX_DIST 1e9

using namespace std;

int V;
int dist[MAX_V+1];
vector<pair<int,int> > graph[MAX_V+1];

pair<int,int> BFS(int start){
    fill(&dist[0],&dist[MAX_V+1],MAX_DIST);

    queue<pair<int,int> > q;
    q.push(make_pair(start,0));
    dist[start] = 0;

    pair<int,int> result = make_pair(start,0);
    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(result.second < cost){
            result.first = cur;
            result.second = cost;
        }
        for(auto next: graph[cur]){
            if(dist[next.first] > cost + next.second){
                q.push(make_pair(next.first,cost + next.second));
                dist[next.first] = cost + next.second;
            }
        }
    }
    return result;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V;
    for(int i=1;i<=V;i++){
        int v;
        cin >> v;
        while(true){
            int node, cost;
            cin >> node;

            if(node == -1)
                break;

            cin >> cost;

            graph[v].push_back(make_pair(node,cost));
        }
    }

    cout << BFS(BFS(1).first).second << '\n';
    return 0;
}