#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int test_case=0; test_case<T; test_case++){
        int n;
        cin >> n;

        map<string,int> m;
        for(int i=0;i<n;i++){
            string name,kind;
            cin >> name >> kind;

            m[kind]++;
        }

        int result = 1;
        for(auto iter=m.begin();iter != m.end(); iter++)
            result *= iter->second+1;
        printf("%d\n",result-1);
    }
    return 0;
}