#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
	int sqr = (int)ceil(sqrt(num)+1);
	for(int i=2;i<=sqr;i++){
		if(num%i == 0)
			return false;
	}
	return true;
}

int main(void){
	int N, cnt = 0;
	cin >> N;

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if(num == 1)
			continue;
		if(num == 2 || num == 3)
			cnt++;
		else
			cnt += isPrime(num);
	}
	cout << cnt << endl;
	return 0;
}