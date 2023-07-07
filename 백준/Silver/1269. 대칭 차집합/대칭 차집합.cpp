#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;

    set<int> unions;
    for(int i=0;i<a;i++){
        int num;
        cin >> num;
        unions.insert(num);
    }
    for(int i=0;i<b;i++){
        int num;
        cin >> num;
        unions.insert(num);
    }
    cout << 2 * unions.size() - (a+b) << endl;
    return 0;
}