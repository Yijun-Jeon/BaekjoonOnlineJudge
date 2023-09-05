#include <stdio.h>
#include <queue>
#include <vector>

#define MAX_N 25

using namespace std;

int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> groups;
int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};
int N;

bool checkPosValid(int row, int col){
	if(row < 0 || row >= N || col < 0 || col >= N)
		return false;
	if(graph[row][col] == 0)
		return false;
	if(visited[row][col])
		return false;

	return true;
}

int BFS(pair<int,int> start){
	queue<pair<int,int> > q;
	q.push(start);
	int cnt = 0;

	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		if(visited[row][col])
			continue;
		visited[row][col] = true;
		cnt++;

		for(int i=0;i<4;i++){
			int rowNext = row + rows[i];
			int colNext = col + cols[i];

			if(checkPosValid(rowNext,colNext))
				q.push(make_pair(rowNext,colNext));
		}
	}

	return cnt;
}

int main(void)
{
   	scanf("%d",&N);
   	for(int i=0;i<N;i++){
		char line[N];
		scanf("%s",line);

		for(int j=0;j<N;j++)
			graph[i][j] = line[j] - '0';
   	}


   	for(int i=0;i<N;i++){
   		for(int j=0;j<N;j++){
   			if(visited[i][j] == false && graph[i][j] == 1)
   				groups.push_back(BFS(make_pair(i,j)));
   		}
   	}
   	sort(groups.begin(),groups.end());

   	printf("%d\n",groups.size());
   	for(int group : groups)
   		printf("%d\n",group);
    return 0;
}