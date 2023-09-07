#include <stdio.h>
#include <queue>

#define MAX_N 100000

using namespace std;

int N,K;
int rows[2] = {-1,1};
bool visited[MAX_N+1];

bool checkPosValid(int pos){
	if(pos < 0 || pos > MAX_N)
		return false;
	if(visited[pos])
		return false;
	return true;
}

int BFS(){
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,N));

	while(!pq.empty()){
		int curDist = -pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if(curPos == K)
			return curDist;

		if(visited[curPos])
			continue;

		visited[curPos] = true;

		if(checkPosValid(curPos * 2))
			pq.push(make_pair(-(curDist+1),curPos * 2));
		for(int i=0;i<2;i++){
			int nextPos = curPos + rows[i];
			int nextDist = curDist + 1;
			if(checkPosValid(nextPos))
				pq.push(make_pair(-nextDist,nextPos));
		}
	}
	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &K);
	printf("%d\n",BFS());
    return 0;
}