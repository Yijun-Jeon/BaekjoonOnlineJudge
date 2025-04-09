#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    queue<int> q;
    for(int i=1;i<=N;i++)
        q.push(i);

    vector<int> vec(M);
    for(int i=0;i<M;i++)
        cin >> vec[i];

    int result = 0;
    for(int i=0;i<M;i++){
        int cnt = 0;
        while(q.front() != vec[i]){
            int front = q.front();
            q.pop();
            q.push(front);
            cnt++;
        }

        result += min(cnt, (int)q.size() - cnt);
        q.pop();
    }
    cout << result << '\n';
    return 0;
}