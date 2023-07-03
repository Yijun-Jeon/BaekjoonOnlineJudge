#include <iostream>
using namespace std;

int main(void){
	int canvas[101][101] = {0};
	int N,sum = 0;

	cin >> N;
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;

		for(int y_1=y;y_1<y+10;y_1++){
			for(int x_1=x;x_1<x+10;x_1++){
				if(canvas[y_1][x_1] == 0){
					canvas[y_1][x_1] = 1;
					sum++;
				}

			}
		}
	}
	cout<<sum<<endl;
	return 0;
}