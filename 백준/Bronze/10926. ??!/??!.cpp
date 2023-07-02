#include <iostream>
using namespace std;

int main(void)
{
    string suffix = "??!";
    string name;
    cin >> name;
    name.append(suffix);
    cout << name << endl;
    return 0;
}
