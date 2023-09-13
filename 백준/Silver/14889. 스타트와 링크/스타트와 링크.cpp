#include <stdio.h>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>

#define MAX_N 20

using namespace std;

int map[MAX_N][MAX_N];
int N;
int minResult = INT_MAX;

int getSynergy(vector<int> team){
	int sum = 0;
	for(int i=0;i<team.size()-1;i++){
		for(int j=i+1;j<team.size();j++){
			sum += map[team[i]][team[j]];
			sum += map[team[j]][team[i]];
		}
	}
	return sum;
}

void func(vector<int> chosen, int last){
	if(chosen.size() == N/2){
		vector<int> unChosen;
		int idx = 0;
		for(int i=0;i<N;i++){
			if(chosen[idx] == i)
				idx++;
			else
				unChosen.push_back(i);
		}
		minResult = min(minResult,abs(getSynergy(chosen)-getSynergy(unChosen)));
		return;
	}
	int remain = N/2 - chosen.size();
	for(int i=last+1; i <= N-remain; i++){
		vector<int> next = chosen;
		next.push_back(i);
		func(next,i);
	}
}

int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&map[i][j]);
		}
	}
	vector<int> chosen(1,0);
	func(chosen,0);	

	printf("%d\n",minResult);
    return 0;
}