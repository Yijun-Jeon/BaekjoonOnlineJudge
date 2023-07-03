#include <iostream>
#include <string>
using namespace std;

int main(void){
	string N;
	int B;
	cin >> N >> B;

	cout << stoi(N,0,B) << endl;
	return 0;
}