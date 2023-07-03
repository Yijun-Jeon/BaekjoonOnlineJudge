#include <iostream>
using namespace std;

int main(void)
{
    int maxNum = 0;
    int maxNumIdx = 0;
    int num;
    for (int i = 0; i < 9; i++)
    {
        cin >> num;
        if (num > maxNum)
        {
            maxNum = num;
            maxNumIdx = i + 1;
        }
    }

    cout << maxNum << endl;
    cout << maxNumIdx << endl;
    return 0;
}
