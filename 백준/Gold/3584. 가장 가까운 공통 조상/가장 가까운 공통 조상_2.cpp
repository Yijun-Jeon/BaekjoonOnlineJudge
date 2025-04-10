#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 10000
#define MAX_K 13

using namespace std;

int N;
int depth[MAX_N+1];
int parent[MAX_K+1][MAX_N+1];
vector<int> graph[MAX_N+1];

int LCA(int x, int y){
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

    if(x != y)
        x = parent[0][x];

    return x;
}

void BFS(int start){
    queue<pair<int,int> > q;
    q.push(make_pair(start,1));
    depth[start] = 1;

    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int next: graph[cur]){
            if(depth[next] == 0){
                q.push(make_pair(next,d+1));
                depth[next] = d+1;
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> N;

        for(int i=1;i<=N;i++)
            graph[i].clear();

        memset(parent,0,sizeof(parent));
        memset(depth,0,sizeof(depth));
        for(int i=0;i<N-1;i++){
            int A,B;
            cin >> A >> B;

            parent[0][B] = A;
            graph[A].push_back(B);
        }

        for(int k=1;k<=MAX_K;k++){
            for(int i=1;i<=N;i++){
                parent[k][i] = parent[k-1][parent[k-1][i]];
            }
        }

        for(int i=1;i<=N;i++){
            if(parent[0][i] == 0){
                BFS(i);
                break;
            }
        }

        int x,y;
        cin >> x >> y;

        cout << LCA(x,y) << '\n';
    }
    return 0;
}