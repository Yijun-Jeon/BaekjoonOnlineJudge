#include <iostream>
#include <string>
using namespace std;

int main(void){
	int N;
	cin >> N;

	for(int i=1;i<N;i++){
		int sum = 0;
		string num = to_string(i);
		for(int j=0;j<num.length();j++){
			sum += (num[j] - '0');
		}
		if(sum+i == N){
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}