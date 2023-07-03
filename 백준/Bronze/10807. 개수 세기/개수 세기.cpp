#include <iostream>
using namespace std;
#define MAX_NUM 200

int main(void)
{
    int nums[MAX_NUM + 1] = {};
    int N, v;

    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        nums[num + 100] += 1;
    }

    cin >> v;
    cout << nums[v + 100] << endl;
    return 0;
}
