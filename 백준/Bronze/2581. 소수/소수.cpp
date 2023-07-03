#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
	if(num == 2 || num == 3)
		return true;
	int sqr = ceil(sqrt(num)+1);
	for(int i=2;i<=sqr;i++){
		if(num%i == 0)
			return false;
	}
	return num != 1;
}

int main(void){
	int M,N;
	int min = 10000, sum = 0;
	cin >> M >> N;
	for(int i=M;i<=N;i++){
		if(isPrime(i)){
			min = min > i ? i : min;
			sum += i;
		}
	}
	if(sum == 0)
		cout << -1 << endl;
	else	
		cout << sum << endl << min << endl;
	return 0;
}