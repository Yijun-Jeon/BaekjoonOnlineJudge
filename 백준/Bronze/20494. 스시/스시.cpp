#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int result = 0;
    for(int i=0;i<N;i++){
        string sushi;
        cin >> sushi;

        result += sushi.length();
    }
    cout << result <<'\n';
    return 0;
}