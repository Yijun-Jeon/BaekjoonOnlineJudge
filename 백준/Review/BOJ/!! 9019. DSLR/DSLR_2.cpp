#include <stdio.h>
#include <cstring>
#include <string>
#include <queue>

#define MAX_N 10000

using namespace std;

string BFS(int A, int B){
    bool visited[MAX_N];
    memset(visited,false,sizeof(visited));
    
    queue<pair<int,string> > q;
    q.push(make_pair(A,""));
    visited[A] = true;

    while(!q.empty()){
        int cur = q.front().first;
        string commands = q.front().second;
        q.pop();

        if(cur == B){
            for(int i=0;i<commands.size();i++)
                printf("%c",commands[i]);
            printf("\n");
            return commands;
        }

        int next;
        // S
        next = (cur+MAX_N-1) % MAX_N;
        if(visited[next] == false){
            visited[next] = true;
            q.push(make_pair(next,commands+"S"));
        }

        // D
        next = (2*cur) % MAX_N;
        if(visited[next] == false){
            visited[next] = true;
            q.push(make_pair(next,commands+"D"));
        }

        // L
        next = (cur%1000)*10 + cur/1000;
        if(visited[next] == false){
            visited[next] = true;
            q.push(make_pair(next,commands+"L"));
        }

        // R
        next = cur%10 * 1000 + (cur/10);
        if(visited[next] == false){
            visited[next] = true;
            q.push(make_pair(next,commands+"R"));
        }
    }
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int t=0;t<T;t++){
        int A,B;
        scanf("%d %d",&A,&B);

        BFS(A,B);
    }
    return 0;
}