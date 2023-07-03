#include <iostream>
using namespace std;
#define MAX_NUM 10000

int main(void)
{
    int maxNum = -1000000;
    int minNum = 1000000;
    int N;

    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        maxNum = num > maxNum ? num : maxNum;
        minNum = num < minNum ? num : minNum;
    }

    cout << minNum << ' ' << maxNum << endl;

    return 0;
}
