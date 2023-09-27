#include <stdio.h>

#define MAX_N 1000000

using namespace std;

int nums[MAX_N];
int dp[MAX_N];
int N;

int binarySearch(int left, int right, int num){
	int mid;

	while(left < right){
		mid = (left+right)/2;

		if(dp[mid] == num)
			return mid;

		if(dp[mid] > num)
			right = mid;
		else
			left = mid+1;
	}
	return right;
}

int main(void)
{
	scanf("%d",&N);

	for(int i=0;i<N;i++)
		scanf("%d",&nums[i]);

	dp[0] = nums[0];

	int idx = 0;
	for(int i=1;i<N;i++){
		if(nums[i] > dp[idx])
			dp[++idx] = nums[i];
		else{
			int pos = binarySearch(0,idx,nums[i]);
			dp[pos] = nums[i];
		}
	}
	printf("%d\n",idx+1);
    return 0;
}