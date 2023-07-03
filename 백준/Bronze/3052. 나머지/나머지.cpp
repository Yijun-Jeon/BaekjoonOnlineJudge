#include <iostream>
#include <numeric>
using namespace std;

int main(void)
{
    int remains[42] = {};

    int num;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        remains[num % 42] = 1;
    }
    cout << accumulate(remains, remains + 42, 0) << endl;
    return 0;
}
