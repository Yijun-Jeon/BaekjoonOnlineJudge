#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>

#define MAX_N 100000
#define MAX_DIST MAX_N*2

using namespace std;

int N,S,D,F,B,K;
int dist[MAX_N+1];
bool isPolice[MAX_N+1];

bool checkPosValid(int x, int d){
    if(x <= 0 || x > N)
        return false;
    if(isPolice[x])
        return false;
    if(dist[x] <= d)
        return false;
    return true;
}

void BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(S,0));

    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if(checkPosValid(cur+F,d+1)){
            q.push(make_pair(cur+F,d+1));
            dist[cur+F] = d+1;
        }

        if(checkPosValid(cur-B,d+1)){
            q.push(make_pair(cur-B,d+1));
            dist[cur-B] = d+1;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> S >> D >> F >> B >> K;
    while(K--){
        int police;
        cin >> police;

        isPolice[police] = true;
    }

    fill(&dist[0],&dist[N+1],MAX_DIST);

    BFS();

    if(dist[D] == MAX_DIST)
        cout << "BUG FOUND" << '\n';
    else
        cout << dist[D] << '\n';
    return 0;
}