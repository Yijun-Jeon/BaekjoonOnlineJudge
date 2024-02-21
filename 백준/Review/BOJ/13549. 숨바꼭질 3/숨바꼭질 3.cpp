#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_N 100000
#define MAX_TIME 1e9

using namespace std;

int times[MAX_N+1];
int N,X;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first + a.second > b.first + b.second;
    }
};

int BFS(int start, int end){
    priority_queue<pair<int,int>, vector<pair<int,int> >,cmp > pq;
    pq.push(make_pair(start,0));

    while(!pq.empty()){
        int curPos = pq.top().first;
        int curTime = pq.top().second;
        pq.pop();

        if(times[curPos] <= curTime)
            continue;
        times[curPos] = curTime;

        if(curPos < end && curPos*2 <= MAX_N && times[curPos*2] > curTime)
            pq.push(make_pair(curPos*2, curTime));
        if(times[curPos-1] > curTime+1)
            pq.push(make_pair(curPos-1,curTime+1));
        if(times[curPos+1] > curTime+1)
            pq.push(make_pair(curPos+1,curTime+1));
    }
    return times[end];
}

int main(void)
{
    scanf("%d %d",&N,&X);

    fill(&times[0],&times[MAX_N+1],MAX_TIME);

    printf("%d\n",BFS(N,X));
    return 0;
}