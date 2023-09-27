#include <stdio.h>
#include <algorithm>

#define MAX_N 100

using namespace std;

pair<int,int> lines[MAX_N];
int dp[MAX_N];

int main(void)
{
	int N;
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		scanf("%d %d",&lines[i].first,&lines[i].second);
		dp[i] = 1;
	}

	sort(lines,lines+N);

	int result = 1;
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(lines[j].second < lines[i].second)
				dp[i] = max(dp[i], dp[j]+1);
		}
		result = max(result,dp[i]);
	}

	printf("%d\n",N-result);
    return 0;
}