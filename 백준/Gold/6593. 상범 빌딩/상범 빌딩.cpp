#include <iostream>
#include <queue>

#define MAX_N 30
#define MAX_DIST 30 * 30 * 30;

using namespace std;

int L,R,C;
char map[MAX_N][MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N];

pair<int,pair<int,int> > S,E;


int rows[6] = {1,0,-1,0,0,0};
int cols[6] = {0,1,0,-1,0,0};
int layers[6] = {0,0,0,0,1,-1};

bool checkPosValid(int layer, int row, int col){
    if(layer < 0 || layer >= L)
        return false;
    if(row < 0 || row >= R)
        return false;
    if(col < 0 || col >= C)
        return false;
    if(map[layer][row][col] == '#')
        return false;
    if(visited[layer][row][col])
        return false;
    return true;
}

int BFS(){
    queue<pair<pair<int,pair<int,int> >, int> > q;
    q.push(make_pair(S,0));

    while(!q.empty()){
        int layer = q.front().first.first;
        int row = q.front().first.second.first;
        int col = q.front().first.second.second;
        int dist = q.front().second;
        q.pop();

        if(visited[layer][row][col])
            continue;
        visited[layer][row][col] = true;

        if(layer == E.first && row == E.second.first && col == E.second.second)
            return dist;

        for(int i=0;i<6;i++){
            int nextLayer = layer + layers[i];
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextLayer,nextRow,nextCol))
                q.push(make_pair(make_pair(nextLayer,make_pair(nextRow,nextCol)),dist+1));
        }
    }
    return -1;   
}


int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> L >> R >> C;
        
        if(L+R+C == 0)
            break;
        
        for(int l=0;l<L;l++){
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    cin >> map[l][r][c];
                    visited[l][r][c] = false;

                    if(map[l][r][c] == 'S'){
                        S.first = l;
                        S.second.first = r;
                        S.second.second = c;
                    }

                    if(map[l][r][c] == 'E'){
                        E.first = l;
                        E.second.first = r;
                        E.second.second = c;
                    }
                }
            }
        }
        int result = BFS();
        if(result == -1){
            cout << "Trapped!" <<'\n';
        }else{
            cout << "Escaped in "<< result << " minute(s)." << '\n';    
        }
    }
    return 0;
}