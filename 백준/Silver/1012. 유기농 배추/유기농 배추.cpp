#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_N 50

using namespace std;

int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};
int T,M,N,K;

void init(){
	memset(map,0,sizeof(map));
	memset(visited,false,sizeof(visited));
}

bool checkPosValid(int row, int col){
	if(row < 0 || row >= N || col < 0 || col >= M)
		return false;
	if(map[row][col] == 0)
		return false;
	if(visited[row][col])
		return false;
	return true;
}

void BFS(pair<int,int> start){
	queue<pair<int,int> > q;
	q.push(start);

	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		if(visited[row][col])
			continue;

		visited[row][col] = true;
		for(int i=0;i<4;i++){
			int rowNext = row + rows[i];
			int colNext = col + cols[i];

			if(checkPosValid(rowNext,colNext))
				q.push(make_pair(rowNext,colNext));
		}
	}
}

int main(void)
{
	scanf("%d",&T);

	for(int test_case=0; test_case < T; test_case++){
		init();
		scanf("%d %d %d",&M,&N,&K);

		for(int i=0;i<K;i++){
			int col,row;
			scanf("%d %d",&col,&row);

			map[row][col] = 1;
		}

		int cnt = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(checkPosValid(i,j)){
					BFS(make_pair(i,j));
					cnt++;
				}
			}
		}

		printf("%d\n",cnt);
	}

    return 0;
}