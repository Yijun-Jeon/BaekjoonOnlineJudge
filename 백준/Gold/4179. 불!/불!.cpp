#include <stdio.h>
#include <queue>

#define MAX_N 1000

using namespace std;

int R,C;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool fired[MAX_N][MAX_N];

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};

queue<pair<int,pair<int,int> > > fireQ;
queue<pair<int,pair<int,int> > > jQ;


bool checkFirePosValid(int row, int col){
    if(row < 0 || row >= R || col < 0 || col >= C)
        return false;
    if(map[row][col] == 'F' || map[row][col] == '#' || fired[row][col])
        return false;
    return true;
}

void BFS(){
    while(!jQ.empty()){
        int time = jQ.front().first;
        int row = jQ.front().second.first;
        int col = jQ.front().second.second;
        jQ.pop();

        while(!fireQ.empty() && fireQ.front().first <= time){
            int timeF = fireQ.front().first;
            int rowF = fireQ.front().second.first;
            int colF = fireQ.front().second.second;
            fireQ.pop();

            if(map[rowF][colF] == 'F')
                continue;
            map[rowF][colF] = 'F';
            fired[rowF][colF] = true;

            for(int i=0;i<4;i++){
                int nextRowF = rowF + rows[i];
                int nextColF = colF + cols[i];
                if(checkFirePosValid(nextRowF,nextColF)){
                    fireQ.push(make_pair(timeF+1,make_pair(nextRowF,nextColF)));
                    fired[rowF][colF] = true;
                }
            }
        }

        if(map[row][col] == 'F')
            continue;
        map[row][col] = 'J';
        visited[row][col] = true;

        for(int i=0;i<4;i++){
            int nextRow = row + rows[i];
            int nextCol = col + cols[i];
            
            if(nextRow < 0 || nextRow >= R || nextCol < 0 || nextCol >= C){
                printf("%d\n",time+1);
                return;
            }

            if(map[nextRow][nextCol] == '.' && visited[nextRow][nextCol] == false){
                jQ.push(make_pair(time+1,make_pair(nextRow,nextCol)));
                visited[nextRow][nextCol] = true;
            }
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(void)
{
    scanf("%d %d",&R,&C);

    int r,c;
    for(int i=0;i<R;i++){
        char line[C+1];
        scanf("%s",line);

        for(int j=0;j<C;j++){
            if(line[j] == 'J')
                jQ.push(make_pair(0,make_pair(i,j)));
            else if(line[j] == 'F')
                fireQ.push(make_pair(0,make_pair(i,j)));
            else
                map[i][j] = line[j];
        }
    }

    BFS();

    return 0;
}