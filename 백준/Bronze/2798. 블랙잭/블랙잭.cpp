#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int N,M;
	cin >> N >> M;

	vector<int> nums(N);
	for(int i=0;i<N;i++)
		cin >> nums[i];

	int max = 0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for(int k=j+1;k<N;k++){
				int temp = nums[i]+nums[j]+nums[k];
				if(temp > max && temp <= M)
					max = temp;
			}
		}
	}
	cout << max << endl;
	return 0;
}