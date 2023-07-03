#include <iostream>
using namespace std;

int main(void){
	int a_1, a_0, c, n;
	cin >> a_1 >> a_0 >> c >> n;

	if(a_1 > c)
		cout << 0 << endl;
	else if(a_1*n + a_0 <= c*n)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}