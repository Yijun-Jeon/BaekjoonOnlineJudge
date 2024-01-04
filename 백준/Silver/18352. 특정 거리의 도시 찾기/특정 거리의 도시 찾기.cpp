#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 300000

using namespace std;

int N,M,K,X;
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];

vector<int> BFS(int start){
    queue<pair<int,int> > q;
    q.push(make_pair(start,0));

    vector<int> result;
    while(!q.empty()){
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(visited[now])
            continue;

        if(dist > K)
            return result;

        if(dist == K)
            result.push_back(now);

        visited[now] = true;
        for(int next: graph[now]){
            if(visited[next] == false)
                q.push(make_pair(next,dist+1));
        }
    }
    return result;
}

int main(void)
{
    scanf("%d %d %d %d",&N,&M,&K,&X);
    for(int i=0;i<M;i++){
        int A,B;
        scanf("%d %d",&A,&B);

        graph[A].push_back(B);
    }

    vector<int> result = BFS(X);
    sort(result.begin(),result.end());
    
    if(result.size() == 0)
        printf("-1\n");
    else{
        for(int city: result)
            printf("%d\n",city);
    }

    return 0;
}