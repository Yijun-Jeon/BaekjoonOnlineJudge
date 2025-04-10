#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100000
#define MAX_K 16

int N,M;
int parent[MAX_K+1][MAX_N+1], depth[MAX_N+1];
vector<int> graph[MAX_N+1];

void BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(1,1));
    depth[1] = 1;

    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int next: graph[cur]){
            if(depth[next] == 0){
                q.push(make_pair(next,d+1));
                depth[next] = d+1;
                parent[0][next] = cur;
            }
        }
    }
}

int LCA(int x,int y){
    if(depth[x] > depth[y])
        swap(x,y);

    for(int k=MAX_K;k>=0;k--){
        if(pow(2,k) <= depth[y] - depth[x])
            y = parent[k][y];
    }

    if(x == y) return x;

    for(int k=MAX_K; k>=0; k--){
        if(parent[k][x] != parent[k][y]){
            x = parent[k][x];
            y = parent[k][y];
        }
    }

    if(x != y) x = parent[0][x];

    return x;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int n=0;n<N-1;n++){
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BFS();

    for(int k=1;k<=MAX_K;k++){
        for(int i=1;i<=N;i++)
            parent[k][i] = parent[k-1][parent[k-1][i]];
    }

    cin >> M;
    while(M--){
        int a,b;
        cin >> a >> b;

        cout << LCA(a,b) << '\n';
    }
    return 0;
}