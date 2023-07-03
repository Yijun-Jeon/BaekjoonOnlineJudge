#include <iostream>
using namespace std;

int main(void){
	int A,B,V;
	cin >> A >> B >> V;

	if(A==V){
		cout << 1 <<endl;
		return 0;
	}

	int cnt = (V-A) / (A-B);
	if((V-A)%(A-B) != 0)
		cnt++;
	cnt = cnt == 0 ? 1 : cnt;
	cout << cnt + 1 << endl;
	return 0;
}