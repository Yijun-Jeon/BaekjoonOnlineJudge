#include <stdio.h>
#include <algorithm>

#define MAX_N 11

using namespace std;

int nums[MAX_N];
int N;
int operators[4];

int maxResult = -1000000000;
int minResult = 1000000000;


void DFS(int idx, int sum){
	if(idx == N){
		maxResult = max(maxResult,sum);
		minResult = min(minResult,sum);
		return;
	}

	for(int i=0;i<4;i++){
		if(operators[i]){
			operators[i]--;
			switch(i){
			case 0:
				DFS(idx+1,sum + nums[idx]);
				break;
			case 1:
				DFS(idx+1,sum - nums[idx]);
				break;
			case 2:
				DFS(idx+1,sum * nums[idx]);
				break;
			case 3:
				DFS(idx+1,sum / nums[idx]);
				break;
			}
			operators[i]++;
		}
	}
}

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d", &nums[i]);

	for(int i=0;i<4;i++)
		scanf("%d", &operators[i]);

	DFS(1,nums[0]);

	printf("%d\n%d\n",maxResult,minResult);	
    return 0;
}