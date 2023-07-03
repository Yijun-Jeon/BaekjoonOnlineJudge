#include <iostream>
using namespace std;

int main(void){
	string A,B;
	cin >> A >> B;

	string result;
	int i = A.length()-1, j = B.length()-1;
	int carry = 0;
	while(i >= 0 || j >= 0){
		int a = i < 0 ? 0 : A[i] - '0';
		int b = j < 0 ? 0 : B[j] - '0';

		int num = a + b + carry;
		if(num >= 10){
			result = to_string(num-10) + result;;
			carry = 1;
		}else{
			result = to_string(num) + result;
			carry = 0;
		}
		i--;
		j--;
	}
	if(carry)
		result = '1' + result;
	cout << result << endl;
	return 0;
}