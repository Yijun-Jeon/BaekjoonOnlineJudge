#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 200

using namespace std;

int parent[MAX_N+1];
int N,M;

int Find(int x){
	if(x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
	int parentX = Find(x);
	int parentY = Find(y);

	if(parentX != parentY)
		parent[parentY] = parentX;
}

int main(void)
{
	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;i++)
		parent[i] = i;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int connected;
			scanf("%d",&connected);

			if(connected)
				Union(i,j);
		}
	}

	string answer = "YES";
	
	int city;
	scanf("%d",&city);
	int load = Find(city);

	for(int i=1;i<M;i++){
		scanf("%d",&city);
		if(load != Find(city))
			answer = "NO";
	}
	cout << answer << '\n';
    return 0;
}