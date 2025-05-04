#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N,K;
int previous[MAX_N+1];
int dist[MAX_N+1];

void printRoute(int n){
    if(previous[n] != n)
        printRoute(previous[n]);
    cout << n << " ";
}

bool checkPosValid(int cur, int d){
    if(cur < 0 || cur > MAX_N)
        return false;
    if(dist[cur] < d)
        return false;
    return true;
}

void BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(N,0));
    previous[N] = N, dist[N] = 0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if(checkPosValid(cur+1,d+1)){
            dist[cur+1] = d+1;
            previous[cur+1] = cur;
            q.push(make_pair(cur+1,d+1));
        }
        if(checkPosValid(cur-1,d+1)){
            dist[cur-1] = d+1;
            previous[cur-1] = cur;
            q.push(make_pair(cur-1,d+1));
        }
        if(checkPosValid(cur*2,d+1)){
            dist[cur*2] = d+1;
            previous[cur*2] = cur;
            q.push(make_pair(cur*2,d+1));
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    fill(&dist[0],&dist[MAX_N+1],MAX_N+1);

    BFS();

    cout << dist[K] << '\n';
    printRoute(K);
    cout << '\n';
    return 0;
}