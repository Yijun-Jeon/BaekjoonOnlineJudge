#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    getchar();
    while(T--){
        string line;
        getline(cin,line);

        stringstream ss(line);
        vector<string> vec;
        string temp;

        while(ss >> temp)
            vec.push_back(temp);

        long long result = stoll(vec[0]);
        switch(vec[1][0]){
        case '+':
            result += stoll(vec[2]);
            break;
        case '-':
            result -= stoll(vec[2]);
            break;
        case '*':
            result *= stoll(vec[2]);
            break;
        case '/':
            result /= stoll(vec[2]);
            break;
        }

        if(result == stoll(vec[4]))
            cout << "correct" << '\n';
        else
            cout << "wrong answer" << '\n';
    }
    return 0;
}