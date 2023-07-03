#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int cnt = 1;
    while(N > 0){
    	string num = to_string(cnt++);
    	if(num.find("666") != -1)
    		N--;
    }
    cout << cnt-1 << endl;
    return 0;
}