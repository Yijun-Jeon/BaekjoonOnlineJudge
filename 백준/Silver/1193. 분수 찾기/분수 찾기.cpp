#include <iostream>
using namespace std;

int main(void){
	int X;
	int cnt = 1, sum = 1;

	cin >> X;

	while(sum < X)
		sum += ++cnt;

	cnt++;
	if(cnt % 2)
		cout << (cnt-1) - (sum - X) << '/' << 1 + (sum-X)  << endl;
	else
		cout << 1 + (sum-X) << '/' << (cnt-1) - (sum - X) << endl;

	return 0;
}