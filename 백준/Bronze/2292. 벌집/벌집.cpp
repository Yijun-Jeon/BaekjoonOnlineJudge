#include <iostream>
using namespace std;

int main(void){
	long long N;
	int cnt = 1,sum = 1;
	
	cin >> N;
	while(sum < N){
		sum += cnt++ * 6;
	}
	cout << cnt << endl;
	return 0;
}