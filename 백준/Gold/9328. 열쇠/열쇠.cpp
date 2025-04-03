#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX_N 100

using namespace std;

int ROW,COL;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool keys[26];

int rows[4] = {1,0,-1,0};
int cols[4] = {0,1,0,-1};

int document,doorCnt;

bool checkPosValid(int row, int col){
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return false;
    if(map[row][col] == '*')
        return false;
    if('A' <= map[row][col] && map[row][col] <= 'Z')
        return keys[map[row][col] - 'A'];
    if('a' <= map[row][col] && map[row][col] <= 'z')
        keys[map[row][col] - 'a'] = true;
    return true;
}

void BFS(int startRow, int startCol){
    memset(visited,false,sizeof(visited));
    
    queue<pair<int,int> > q;
    q.push(make_pair(startRow,startCol));
    visited[startRow][startCol] = true;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(map[row][col] == '$'){
            document--;
            map[row][col] = '.';
        }

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            if(checkPosValid(nextRow,nextCol)){
                if(visited[nextRow][nextCol] == false){
                    q.push(make_pair(nextRow,nextCol));
                    visited[nextRow][nextCol] = true;
                }
            }
        }
    }
}


int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> ROW >> COL;

        document = 0;
        for(int r=0;r<ROW;r++){
            for(int c=0;c<COL;c++){
                cin >> map[r][c];

                if(map[r][c] == '$')
                    document++;

                if('A' <= map[r][c] && map[r][c] <= 'Z')
                    doorCnt++;
            }
        }

        string key;
        cin >> key;

        memset(keys,false,sizeof(keys));
        if(key != "0"){
            for(char c: key){
                keys[c-'a'] = true;
            }
        }

        int result = document;
        doorCnt++;
        while(document && doorCnt){
            for(int r=0;r<ROW;r++){
                for(int c=0;c<COL;c++){
                    if(r == 0 || r == ROW-1 || c == 0 || c == COL-1){
                        if(checkPosValid(r,c))
                            BFS(r,c);
                    }
                }
            }
            doorCnt--;
        }
        cout << result - document << '\n';
    }
    return 0;
}