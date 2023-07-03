#include <iostream>
#define MAX(A,B) (((A) > (B)) ? (A) : (B))
using namespace std;

int main(void){
	int a,b,c;

	cin >> a >> b >> c;
	int maxNum = MAX(a,b);
	maxNum = MAX(maxNum,c);

	if(a+b+c - maxNum > maxNum)
		cout << a+b+c << endl;
	else
		cout << 2*(a+b+c - maxNum)-1 << endl;

	return 0;
}