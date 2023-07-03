#include <iostream>
#define MIN(A,B) (((A) > (B)) ? (B) : (A))
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int min = 5000;
    for(int i=0;i<=N/5;i++){
    	int remain = (N - 5*i);
    	if(remain % 3 != 0)
    		continue;
    	min = MIN(min,i+remain/3);
    }
    min = min == 5000 ? -1 : min;
	cout << min << endl;
    return 0;
}