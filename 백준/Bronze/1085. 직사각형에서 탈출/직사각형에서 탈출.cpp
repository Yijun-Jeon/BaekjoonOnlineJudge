#include <iostream>
using namespace std;

int main(void){
	int x,y,w,h;
	cin >> x >> y >> w >> h;

	int distance = 10001;
	distance = distance > x ? x : distance;
	distance = distance > y ? y : distance;
	distance = distance > w-x ? w-x : distance;
	distance = distance > h-y ? h-y : distance;
	cout << distance <<endl;
	return 0;
}