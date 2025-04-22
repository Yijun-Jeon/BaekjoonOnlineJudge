#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N,K;
int dist[MAX_N+1];

bool checkPosValid(int x, int d){
    if(x<0 || x > MAX_N)
        return false;
    if(dist[x] <= d)
        return false;
    return true;
}

int BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(N,0));
    dist[N] = 0;

    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if(checkPosValid(cur+1,d+1)){
            q.push(make_pair(cur+1,d+1));
            dist[cur+1] = d+1;
        }

        if(checkPosValid(cur-1,d+1)){
            q.push(make_pair(cur-1,d+1));
            dist[cur-1] = d+1;
        }

        if(checkPosValid(cur*2,d)){
            q.push(make_pair(cur*2,d));
            dist[cur*2] = d;
        }
    }
    return dist[K];
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    fill(&dist[0],&dist[MAX_N+1],MAX_N+1);

    cout << BFS() << '\n';
    return 0;
}