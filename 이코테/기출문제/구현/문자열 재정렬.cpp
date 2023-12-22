#include <stdio.h>
#include <cstring>
#include <algorithm>

#define MAX_LEN 10000

using namespace std;

int main(void)
{
	char S[MAX_LEN+1];
	vector<char> alpha;

	scanf("%s",S);

	int sum = 0;
	for(int i=0;i<(int)strlen(S);i++){
		if('0' <= S[i] && S[i] <= '9')
			sum += S[i] - '0';
		else
			alpha.push_back(S[i]);
	}

	sort(alpha.begin(),alpha.end());
	for(int i=0;i<alpha.size();i++)
		printf("%c",alpha[i]);
	printf("%d\n",sum);
    return 0;
}