#include <iostream>
using namespace std;
#define MAX_NUM 10000

int main(void)
{
    int nums[MAX_NUM] = {};
    int N, X;

    cin >> N >> X;
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    for (int i = 0; i < N; i++)
        if (nums[i] < X)
            cout << nums[i] << ' ';
    cout << endl;

    return 0;
}
