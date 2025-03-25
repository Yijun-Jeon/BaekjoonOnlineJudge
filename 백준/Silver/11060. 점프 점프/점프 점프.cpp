#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 1000
#define MAX_DIST 10000000

using namespace std;

int N;
int dist[MAX_N];
int map[MAX_N];

void BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));

    while(!q.empty()){
        int cur = q.front().first;
        int jump = q.front().second;
        q.pop();

        if(dist[cur] <= jump)
            continue;
        dist[cur] = jump;

        for(int i=cur+1;i <= cur + map[cur];i++){
            if(i >= N)
                break;
            if(dist[i] > jump+1)
                q.push(make_pair(i,jump+1));
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i=0;i<N;i++)
        cin >> map[i];

    fill(&dist[0],&dist[MAX_N],MAX_DIST);

    BFS();

    if(dist[N-1] == MAX_DIST)
        dist[N-1] = -1;
    cout << dist[N-1] << '\n';
    return 0;
}