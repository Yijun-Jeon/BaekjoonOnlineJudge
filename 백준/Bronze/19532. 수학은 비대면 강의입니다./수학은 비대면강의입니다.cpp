#include <iostream>
using namespace std;

int main(void)
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    for(int x=-999;x<=999;x++){
    	for(int y=-999;y<=999;y++){
    		if(a*x + b*y != c)
    			continue;
    		if(d*x + e*y != f)
    			continue;

    		cout << x << ' ' << y << endl;
    		return 0;
    	}
    }
    return 0;
}