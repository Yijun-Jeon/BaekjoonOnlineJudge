#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	string S;
	cin >> S;

	int last = S[S.size()-1] - '0';
	int prev = last;
	int result = 0;
	for(int i=S.size()-1;i>=0;i--){
		int now = S[i] - '0';
		if(now != last && now != prev)
			result++;
		prev = now;
	}
	printf("%d\n",result);
    return 0;
}