#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 10000

using namespace std;

char last[MAX_N];
int parent[MAX_N];

void backtracking(int B){
    string result;
    int cur = B;
    while(parent[cur] != cur){
        result = last[cur] + result;
        cur = parent[cur];
    }
    
    cout << result << '\n';
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        fill(&parent[0],&parent[MAX_N],-1);
        fill(&last[0],&last[MAX_N],'\0');
        
        int A,B;
        cin >> A >> B;

        queue<int> q;
        q.push(A);
        parent[A] = A;
        last[A] = 'O';

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int next = (cur*2)%MAX_N;
            if(!last[next]){
                q.push(next);
                last[next] = 'D';
                parent[next] = cur;
                if(next == B){
                    backtracking(B);
                    break;
                }
            }

            next = (cur+MAX_N-1)%MAX_N;
            if(!last[next]){
                q.push(next);
                last[next] = 'S';
                parent[next] = cur;
                if(next == B){
                    backtracking(B);
                    break;
                }
            }

            next = (cur%1000)*10 + cur/1000;
            if(!last[next]){
                q.push(next);
                last[next] = 'L';
                parent[next] = cur;
                if(next == B){
                    backtracking(B);
                    break;
                }
            }

            next = (cur%10) * 1000 + cur/10;
            if(!last[next]){
                q.push(next);
                last[next] = 'R';
                parent[next] = cur;
                if(next == B){
                    backtracking(B);
                    break;
                }
            }
        }
    }
    return 0;
}