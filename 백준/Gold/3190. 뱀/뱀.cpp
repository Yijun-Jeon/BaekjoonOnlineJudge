#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_N 100

using namespace std;

int N,K,L;
// 0 : 빈칸, 1 : 사과, 2 : 뱀
int map[MAX_N+1][MAX_N+1];
queue<pair<int,char> > q;

int rows[4] = {0,1,0,-1};
int cols[4] = {1,0,-1,0};

bool checkEnd(int row, int col){
    if(row < 1 || row > N || col < 1 || col > N)
        return true;
    if(map[row][col] == 2)
        return true;
    return false;
}

int main(void)
{
    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++){
        int row,col;
        scanf("%d %d",&row,&col);

        map[row][col] = 1;
    }
    map[1][1] = 2;

    scanf("%d",&L);
    for(int i=0;i<L;i++){
        int X;
        char C;
        scanf("%d %c",&X,&C);

        q.push(make_pair(X,C));
    }

    vector<pair<int,int> > snake;
    snake.push_back(make_pair(1,1));
    int dir = 0;

    int result = 0;
    while(true){
        int headRow = snake[0].first;
        int headCol = snake[0].second;

        // 이동
        int nextRow = headRow + rows[dir];
        int nextCol = headCol + cols[dir];
        snake.insert(snake.begin(),make_pair(nextRow,nextCol));

        result++;

        // 종료 검사
        if(checkEnd(nextRow,nextCol))
            break;
        
        // 이동 칸에 사과가 있음
        if(map[nextRow][nextCol] == 0){
            map[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        map[nextRow][nextCol] = 2;

        // 회전 시간
        if(result == q.front().first){
            if(q.front().second == 'L')
                dir = (dir+3) % 4;
            else if(q.front().second == 'D')
                dir = (dir+1) % 4;
            q.pop();
        }
    }

    printf("%d\n",result);
    return 0;
}