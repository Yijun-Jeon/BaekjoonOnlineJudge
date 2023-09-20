#include <stdio.h>
#include <utility>
#include <algorithm>

#define MAX_N 100000

using namespace std;

pair<int,int> meetings[MAX_N];
int N;

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&meetings[i].second,&meetings[i].first);
	}

	sort(meetings,meetings+N);

	int cnt = 1;
	int time = meetings[0].first;
	for(int i=1;i<N;i++){
		if(meetings[i].second < time)
			continue;
		time = meetings[i].first;
		cnt++;
	}

	printf("%d\n",cnt);
    return 0;
}