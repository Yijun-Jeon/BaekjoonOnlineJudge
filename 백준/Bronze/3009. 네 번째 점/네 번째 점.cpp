#include <iostream>
using namespace std;

int main(void){
	int xs[1001] = {0};
	int ys[1001] = {0};

	for(int i=0;i<3;i++){
		int x,y;
		cin >> x >> y;

		xs[x]++;
		ys[y]++;

	}
	for(int i=0;i<1001;i++){
		if(xs[i] == 1)
			cout << i << ' ';
	}
	for(int i=0;i<1001;i++){
		if(ys[i] == 1)
			cout << i << endl;
	}
	return 0;
}