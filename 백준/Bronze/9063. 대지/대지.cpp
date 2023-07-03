#include <iostream>
using namespace std;

int main(void){
	int N;
	int minX = 10000, minY = 10000;
	int maxX = -10000, maxY = -10000;

	cin >> N;
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;
		
		minX = minX > x ? x : minX;
		minY = minY > y ? y : minY;
		maxX = maxX < x ? x : maxX;
		maxY = maxY < y ? y : maxY;
	}

	cout << (maxY - minY) * (maxX - minX) << endl;
	return 0;
}