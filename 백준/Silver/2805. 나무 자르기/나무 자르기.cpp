#include <stdio.h>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

int trees[MAX_N];
int N,M;

int bianrySearch(int left, int right){
	int answer = 0;
	while(left <= right){
		int mid = (left + right) / 2;

		long long sum = 0;
		for(int tree: trees)
			sum += tree - mid <= 0 ? 0 : tree - mid;

		if(sum >= M){
			answer = max(answer, mid);
			left = mid+1;
		}else
			right = mid-1;
	}
	return answer;
}

int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&trees[i]);

	printf("%d\n",bianrySearch(0,*max_element(trees,trees+N)));
    return 0;
}