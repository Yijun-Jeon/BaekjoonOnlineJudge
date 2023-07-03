#include <iostream>
using namespace std;

int main(void)
{
    int chess[6] = {1, 1, 2, 2, 2, 8};
    int input[6];

    for (int i = 0; i < 6; i++)
    {
        cin >> input[i];
        chess[i] -= input[i];
    }
    for (int i : chess)
        cout << i << ' ';
    cout << endl;
    return 0;
}