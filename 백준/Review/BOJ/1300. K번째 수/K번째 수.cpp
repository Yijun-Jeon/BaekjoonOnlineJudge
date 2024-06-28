#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

ll N,k;

ll binarySearch(ll left, ll right){
	while(left <= right){
		ll mid = (left + right) / 2;

		ll cnt = 0;
		for(int i=1;i<=N;i++)
			cnt += mid / i > N ? N : mid / i;

		if(cnt >= k){
			right = mid-1;
		}else
			left = mid+1;
	}
	return left;
}

int main(void)
{
	scanf("%lld %lld",&N, &k);
	printf("%lld\n",binarySearch(0,N*N));
    return 0;
}