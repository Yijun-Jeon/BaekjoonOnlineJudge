#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	scanf("%d",&N);

	int nums[N];
	for(int i=0;i<N;i++)
		scanf("%d",&nums[i]);

	sort(nums,nums+N);

	int target = 1;
	for(int i=0;i<N;i++){
		if(target < nums[i])
			break;
		target += nums[i];
	}
	printf("%d\n",target);
    return 0;
}