#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	string N;
	cin >> N;

	int left = 0,right = 0;
	for(int i=0;i<N.size();i++){
		if(i < N.size()/2)
			left += N[i] - '0';
		else
			right += N[i] - '0';
	}
	if(left == right)
		printf("%s\n","LUCKY");
	else
		printf("%s\n","READY");
    return 0;
}