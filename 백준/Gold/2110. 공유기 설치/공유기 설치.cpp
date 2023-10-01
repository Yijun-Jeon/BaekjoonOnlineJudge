#include <stdio.h>
#include <algorithm>

#define MAX_N 200000
#define MAX_DIST 1e9

using namespace std;

int homes[MAX_N];
int N,C;

int binarySearch(){
	int left = 1;
	int right = homes[N-1] - homes[0];

	int result = 0;
	while(left <= right){
		int mid = (left+right)/2;

		int cnt = 1;
		int pos = homes[0];
		for(int home: homes){
			if(pos + mid <= home){
				cnt++;
				pos = home;
			}
		}

		if(cnt >= C){
			left = mid+1;
			result = mid; 
		}
		else
			right = mid-1;
	}
	return result;
}

int main(void)
{
	scanf("%d %d",&N,&C);

	for(int i=0;i<N;i++)
		scanf("%d",&homes[i]);

	sort(homes,homes+N);
	printf("%d\n",binarySearch());
    return 0;
}