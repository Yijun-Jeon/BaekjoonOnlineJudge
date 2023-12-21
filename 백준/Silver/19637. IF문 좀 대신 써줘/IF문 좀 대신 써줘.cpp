#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

#define MAX_N 10000

using namespace std;

int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);

	map<int,string> m;
	for(int i=0;i<N;i++){
		int power;
		string name;

		cin >> name >> power;
		if(m[power] == "")
			m[power] = name;
	}

	for(int i=0;i<M;i++){
		int power;
		scanf("%d",&power);

		cout << m.lower_bound(power)->second << '\n';
	}
    return 0;
}