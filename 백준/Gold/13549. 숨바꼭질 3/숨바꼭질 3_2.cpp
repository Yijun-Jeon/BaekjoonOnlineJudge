#include <stdio.h>
#include <queue>

#define MAX_N 100000

using namespace std;

int N,K;
bool visited[MAX_N+1];

int main(void)
{
    scanf("%d %d",&N,&K);

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,N));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == K){
            printf("%d\n",cost);
            break;
        }

        if(visited[cur])
            continue;
        visited[cur] = true;

        if(cur*2 <= MAX_N && visited[cur*2] == false)
            pq.push(make_pair(-cost,cur*2));
        if(cur+1 <= MAX_N && visited[cur+1] == false)
            pq.push(make_pair(-cost-1,cur+1));
        if(cur-1 >= 0 && visited[cur-1] == false)
            pq.push(make_pair(-cost-1,cur-1));
    }
    return 0;
}