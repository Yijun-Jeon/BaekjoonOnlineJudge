#include <iostream>

#define DENOMI 20000303

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string N;
	cin >> N;
	
	int result = 0;
	for(int i=0;i<N.size();i++)
		result = (result * 10 + (N[i] - '0')) % DENOMI;
	cout << result << '\n';
    return 0;
}

