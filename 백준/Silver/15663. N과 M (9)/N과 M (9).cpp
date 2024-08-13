#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MAX_N 8

using namespace std;

int N,M;
int nums[MAX_N];
bool visited[MAX_N];
vector<string> result;
unordered_map<string,bool> m;


void DFS(int idx, string s){
    if(idx == M){
        result.push_back(s);
        return;
    }

    for(int i=0;i<N;i++){
        if(visited[i])
            continue;

        visited[i] = true;
        DFS(idx+1,s+to_string(nums[i])+" ");
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

    DFS(0,"");

    for(int i=0;i<result.size();i++){
        if(m.find(result[i]) != m.end())
            continue;

        cout << result[i] << '\n';
        m[result[i]] = true;
    }
    return 0;
}