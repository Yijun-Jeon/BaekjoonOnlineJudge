#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define MAX_K 100000

using namespace std;

int N,K;
int dp[MAX_N+1][MAX_K+1];
vector<pair<int,int> > items;

int knapsack(){
	for(int i=items[0].first; i<=K; i++){
		dp[0][i] = items[0].second;
	}

	for(int i=1;i<N;i++){
		for(int j=1;j<=K;j++){
			if(j - items[i].first >= 0)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i].first] + items[i].second);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[N-1][K];
}


int main(void)
{
	scanf("%d %d", &N, &K);
	for(int i=0;i<N;i++){
		int W,V;
		scanf("%d %d", &W, &V);

		items.push_back(make_pair(W,V));
	}

	printf("%d\n",knapsack());

    return 0;
}