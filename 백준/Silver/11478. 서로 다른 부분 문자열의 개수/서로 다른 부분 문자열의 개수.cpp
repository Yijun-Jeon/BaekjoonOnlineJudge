#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    string S;
    set<string> subStrs;
    cin >> S;

    int len = 1;
    while(len <= S.size()){
        for(int i=0;i+len <= S.size();i++){
            string subStr = S.substr(i,len);
            subStrs.insert(subStr);
        }
        len++;
    }
    cout << subStrs.size() << endl;
    return 0;
}