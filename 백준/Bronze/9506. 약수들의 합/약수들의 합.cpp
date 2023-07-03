#include <iostream>
#include <queue>
using namespace std;

int main(void){
	while(true){
		int n;
		cin >> n;
		if(n == -1)
			break;

		queue<int> divisors;
		int sum = 0;
		for(int i=1;i<n;i++){
			if(n%i == 0){
				sum += i;
				divisors.push(i);
			}
		}
		if(sum == n){
			cout << n << " = ";
			while(!divisors.empty()){
				cout << divisors.front();
				if(divisors.size() > 1)
					cout << " + ";
				divisors.pop();
			}
			cout << endl;
		}
		else
			cout << n << " is NOT perfect." << endl;
	}
	return 0;
}