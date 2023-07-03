#include <iostream>
#define MAX(A,B) (((A) > (B)) ? (A) : (B))
using namespace std;

int main(void){
	while(true){
		int a,b,c;
		cin >> a >> b >> c;

		if(a+b+c == 0)
			break;

		int maxNum = MAX(a,b);
		maxNum = MAX(maxNum,c);

		if(a+b+c - maxNum <= maxNum)
			cout << "Invalid" << endl;
		else if(a == b && b == c)
			cout << "Equilateral" << endl;
		else if(a != b && b != c && a != c)
			cout << "Scalene" << endl;
		else
			cout << "Isosceles" << endl;	
	}
	return 0;
}