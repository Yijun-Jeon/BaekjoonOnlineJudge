#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_N 1000

using namespace std;

int times[MAX_N+1];
bool visited[MAX_N+1];
vector<int> graph[MAX_N+1];

int DFS(int now){
    if(visited[now])
        return times[now];

    visited[now] = true;
    int prevMax = 0;
    for(int prev: graph[now])
        prevMax = max(prevMax,DFS(prev));

    times[now] += prevMax;
    return times[now];
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        int N,K;
        cin >> N >> K;

        for(int n=1;n<=N;n++){
            cin >> times[n];
            graph[n].clear();
        }

        for(int k=0;k<K;k++){
            int X,Y;
            cin >> X >> Y;

            graph[Y].push_back(X);
        }

        int W;
        cin >> W;
        
        memset(visited,false,sizeof(visited));

        cout << DFS(W) << '\n';
    }
    return 0;
}