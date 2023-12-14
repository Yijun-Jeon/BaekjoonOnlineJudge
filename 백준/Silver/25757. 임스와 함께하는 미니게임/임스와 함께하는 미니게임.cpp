#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> people;

int main(void)
{
	int N;
	char game;

	scanf("%d %c",&N,&game);

	for(int i=0;i<N;i++){
		string name;
		cin >> name;

		people[name] = true;
	}

	int div;
	if(game == 'Y')
		div = 1;
	else if(game == 'F')
		div = 2;
	else if(game == 'O')
		div = 3;

	printf("%d\n",people.size() / div);
    return 0;
}