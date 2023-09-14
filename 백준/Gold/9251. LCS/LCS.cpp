#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX_LEN 1000

using namespace std;

char s1[MAX_LEN+1], s2[MAX_LEN+1];
int dp[MAX_LEN+1][MAX_LEN+1];

int LCS(int s1Len, int s2Len){
	for(int i=0;i<s1Len;i++){
		for(int j=0;j<s2Len;j++){
			if(s1[i] == s2[j]){
				dp[i+1][j+1] = dp[i][j]+1;
			}else{
				dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
			}
		}
	}

	return dp[s1Len][s2Len];
}

int main(void)
{
	scanf("%s %s",s1,s2);
	printf("%d\n",LCS(strlen(s1),strlen(s2)));
    return 0;
}

