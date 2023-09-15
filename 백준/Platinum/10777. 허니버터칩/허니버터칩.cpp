#include <stdio.h>
#include <algorithm>

#define MAX_N 3000
#define MAX_M 100

using namespace std;

int dp[MAX_N+1][MAX_M+1][MAX_M+1][2];
int N,M;
int arrN[MAX_N+1],arrM[MAX_M+1];
int result = 0;

int take(int idx, int choose, int discard, bool taken){
	// 하나의 case 완성
	if(idx == N && choose + discard == M){
		return dp[idx][choose][discard][taken];
	}

	int &result = dp[idx][choose][discard][taken];
	
	if(result != 0)
		return result;

	// 이전 과자를 선택한 경우 이번 과자 선택 불가 -> 하나는 버려야 함
	if(taken){
		if(idx < N){
			// N 봉지에서 버림
			result = max(result,take(idx+1,choose,discard,false));	
		}
			// M 봉지에서 버림
		if(choose + discard < M){
			result = max(result,take(idx,choose,discard+1,false));	
		}
	// 이전 과자를 선택하지 경우 이번 과자 선택 or 선택 x -> 선택 or 버림
	}else{
		if(idx < N){
			// N 봉지에서 선택
			result = max(result,take(idx+1,choose,discard,true) + arrN[idx]);
			// N 봉지에서 버림
			result = max(result,take(idx+1,choose,discard,false));	
		}
		if(choose + discard < M){
			// M 봉지에서 선택
			result = max(result,take(idx,choose+1,discard,true) + arrM[choose]);
			// M 봉지에서 버림 
			result = max(result, take(idx,choose,discard+1,false));
		}
	}
	return result;
}

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&arrN[i]);
	}

	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d",&arrM[i]);
	}

	sort(arrM,arrM+M,greater<int>());
	printf("%d\n",take(0,0,0,0));
    return 0;
}