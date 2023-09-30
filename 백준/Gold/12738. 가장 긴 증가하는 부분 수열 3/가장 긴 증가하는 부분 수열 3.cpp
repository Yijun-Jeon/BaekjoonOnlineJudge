#include <stdio.h>

#define MAX_N 1000000

using namespace std;

int nums[MAX_N];
int dp[MAX_N];
int N;

int binarySearch(int left, int right, int target){
	while(left < right){
		int mid = (left+right) / 2;
		if(dp[mid] == target)
			return mid;

		if(dp[mid] < target)
			left = mid + 1;
		if(dp[mid] > target)
			right = mid;
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