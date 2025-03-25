#include <iostream>
#include <string>
#include <queue>
#include <cstring>

#define MAX_N 10000

using namespace std;

int A,B;
bool visited[MAX_N];

string BFS(){
    queue<pair<int,string> > q;
    q.push(make_pair(A,""));
    visited[A] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        string commands = q.front().second;
        q.pop();

        if(cur == B)
            return commands;

        // D
        int nextD = (2*cur) % MAX_N;
        if(!visited[nextD]){
            visited[nextD] = true;
            q.push(make_pair(nextD,commands+'D'));    
        }

        // S
        int nextS = (cur+9999) % MAX_N;
        if(!visited[nextS]){
            visited[nextS] = true;
            q.push(make_pair(nextS,commands+'S'));    
        }        
        
        // L
        int nextL = (cur%1000)*10 + cur/1000;
        if(!visited[nextL]){
            visited[nextL] = true;
            q.push(make_pair(nextL,commands+'L'));
        } 

        // R
        int nextR = (cur%10)*1000 + cur/10;
        if(!visited[nextR]){
            visited[nextR] = true;
            q.push(make_pair(nextR,commands+'R'));    
        }
    }
    return "";
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int test_case=0;test_case<T;test_case++){
        memset(visited,false,sizeof(visited));

        cin >> A >> B;

        cout << BFS() << '\n';
    }
    return 0;
}