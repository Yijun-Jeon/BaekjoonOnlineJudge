#include <iostream>
#include <string>
using namespace std;

int main(void){
	int N;
	int B;
	cin >> N >> B;

	string s;
	while(N>0){
		if(N % B < 10){
			s = (char)(N%B+'0') + s;
		}
		else{
			s = (char)(N%B-10+'A') + s;
		}
		N /= B;
	}
	cout << s << endl;
	return 0;
}