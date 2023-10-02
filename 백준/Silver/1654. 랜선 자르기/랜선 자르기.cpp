#include <stdio.h>
#include <algorithm>

#define MAX_K 10000
#define ll long long
using namespace std;

int lines[MAX_K+1];
int K,N;

ll binarySearch(ll left, ll right){
	ll maxLine = 0;

	while(left <= right){
		ll mid = (left+right)/2;

		ll cnt = 0;
		for(int i=0;i<K;i++)
			cnt += lines[i] / mid;

		if(cnt >= N){
			left = mid + 1;
			maxLine = max(maxLine,mid);
		}else
			right = mid - 1;
	}

	return maxLine;
}

int main(void)
{
	int maxNum = 0;
	scanf("%d %d",&K,&N);
	for(int i=0;i<K;i++){
		scanf("%d",&lines[i]);
		maxNum = max(maxNum, lines[i]);
	}

	printf("%lld\n",binarySearch(1,maxNum));
    return 0;
}