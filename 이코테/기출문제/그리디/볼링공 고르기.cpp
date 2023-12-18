#include <iostream>
#include <stdio.h>

#define MAX_M 10

using namespace std;

int balls[MAX_M+1];

int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++){
		int ball;
		scanf("%d",&ball);

		balls[ball]++;
	}

	int result = 0;
	for(int i=1;i<=M;i++){
		for(int j=i+1;j<=M;j++){
			if(balls[i] != 0 && balls[j] != 0)
				result += balls[i] * balls[j];
		}
	}
	printf("%d\n",result);
    return 0;
}