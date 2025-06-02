#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 10000

using namespace std;

bool visited[MAX_N];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        memset(visited,false,sizeof(visited));
        
        int A,B;
        cin >> A >> B;

        queue<pair<int,string> > q;
        q.push(make_pair(A,""));
        visited[A] = true;

        while(!q.empty()){
            int cur = q.front().first;
            string cmd = q.front().second;
            q.pop();

            // D
            int next = (cur*2)%MAX_N;
            if(next == B){
                cout << cmd + "D" << '\n';
                break;
            }else if(!visited[next]){
                q.push(make_pair(next, cmd+"D"));
                visited[next] = true;
            }

            // S
            next = (cur+MAX_N-1)%MAX_N;
            if(next == B){
                cout << cmd + "S" << '\n';
                break;
            }else if(!visited[next]){
                q.push(make_pair(next, cmd+"S"));
                visited[next] = true;
            }

            // L
            next = (cur%1000)*10 + cur/1000;
            if(next == B){
                cout << cmd + "L" << '\n';
                break;
            }else if(!visited[next]){
                q.push(make_pair(next, cmd+"L"));
                visited[next] = true;
            }

            // R
            next = (cur%10) * 1000 + cur/10;
            if(next == B){
                cout << cmd + "R" << '\n';
                break;
            }else if(!visited[next]){
                q.push(make_pair(next, cmd+"R"));
                visited[next] = true;
            }            
        }
    }
    return 0;
}