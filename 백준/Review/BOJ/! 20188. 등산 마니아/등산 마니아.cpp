#include <stdio.h>
#include <vector>

#define MAX_N 300000

using namespace std;

int N;
bool visited[MAX_N+1];
vector<int> graph[MAX_N+1];

long long result;

long long comb(long long n){
    return n * (n-1) / 2;
}

int DFS(int cur){
    visited[cur] = true;

    int cnt = 1;
    for(int next: graph[cur]){
        if(visited[next] == false){
            int below = DFS(next);
            result += comb(N) - comb(N-below);
            cnt += below;
        }
    }
    
    return cnt;
}

int main(void)
{
    scanf("%d",&N);
    for(int n=0;n<N-1;n++){
        int i,j;
        scanf("%d %d",&i,&j);

        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    DFS(1);

    printf("%lld\n",result);
    return 0;
}