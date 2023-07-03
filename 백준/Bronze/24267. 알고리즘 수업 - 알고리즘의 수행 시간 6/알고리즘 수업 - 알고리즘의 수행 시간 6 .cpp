#include <iostream>
#define FUNC(N) ((N) * ((N)+1) / (2))
using namespace std;

int main(void){
	long long  n;
	cin >> n;

	long long cnt = 0;
	for(long long i=1;i<=n-2;i++)
		cnt += FUNC(i);

	cout << cnt << endl;
	cout << 3 << endl;
	return 0;
}