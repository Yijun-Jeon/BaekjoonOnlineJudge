#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 8

using namespace std;

int N,M;
int nums[MAX_N];
vector<string> vec;

bool used[MAX_N];

void DFS(int cnt,string s){
    if(cnt == M){
        vec.push_back(s);
        return;
    }

    for(int i=0;i<N;i++){
        if(!used[i]){
            used[i] = true;
            DFS(cnt+1,s+" "+to_string(nums[i]));
            used[i] = false;
        }
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

    cout << vec[0].substr(1) << '\n';
    for(int i=1;i<vec.size();i++){
        if(vec[i] == vec[i-1])
            continue;
        cout << vec[i].substr(1) << '\n';
    }
    return 0;
}