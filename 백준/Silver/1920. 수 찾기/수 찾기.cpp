#include <stdio.h>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int nums[MAX_N];
int targets[MAX_N];
int N,M;

bool binarySearch(int left, int right, int target){
	while(left <= right){
		int mid = (left + right) / 2;

		if(nums[mid] == target)
			return true;

		if(nums[mid] > target)
			right = mid-1;
		else
			left = mid+1;
	}
	return false;
}

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&nums[i]);

	sort(nums,nums+N);

	scanf("%d",&M);
	for(int i=0;i<M;i++)
		scanf("%d",&targets[i]);

	for(int i=0;i<M;i++)
		printf("%d\n",binarySearch(0,N-1,targets[i]));

    return 0;
}