#include <iostream>
using namespace std;

int main(void){
	int N;
	cin >> N;

	int cnt = 2;
	for(int i=0;i<N;i++)
		cnt = cnt*2 - 1;
	cout << cnt * cnt << endl;
	return 0;
}