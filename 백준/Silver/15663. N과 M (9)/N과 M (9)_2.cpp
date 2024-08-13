#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 8

using namespace std;

int N,M;
int nums[MAX_N];
int result[MAX_N];
bool visited[MAX_N];

void DFS(int idx){
    if(idx == M){
        for(int i=0;i<M;i++)
            cout << result[i] << " ";
        cout << '\n';
        return;
    }

    int prev = 0;
    for(int i=0;i<N;i++){
        if(visited[i] || prev == nums[i])
            continue;

        visited[i] = true;
        result[idx] = prev = nums[i];
        DFS(idx+1);
        visited[i] = false;
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> nums[i];

    sort(&nums[0],&nums[N]);

    DFS(0);
    return 0;
}