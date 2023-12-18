#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	string S;
	cin >> S;

	int result = 0;
	for(int i=0;i<S.size();i++){
		if(result <= 1 || S[i] - '0' <= 1)
			result += S[i] - '0';
		else
			result *= S[i] - '0';
	}

	printf("%d\n",result);
    return 0;
}