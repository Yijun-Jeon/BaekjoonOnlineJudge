#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 100

int main(void)
{
    vector<int> v(30);
    int n;
    for (int i = 0; i < 28; i++)
    {
        cin >> n;
        v[n - 1] = 1;
    }

    int firstIdx = min_element(v.begin(), v.end()) - v.begin();
    int secondIdx = min_element(v.begin() + firstIdx + 1, v.end()) - v.begin();
    cout << min(firstIdx, secondIdx) + 1 << endl;
    cout << max(firstIdx, secondIdx) + 1 << endl;
    return 0;
}
