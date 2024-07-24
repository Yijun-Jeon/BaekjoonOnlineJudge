#include <iostream>
#include <list>
#include <string>

#define MAX_N 100000

using namespace std;

list<int> li;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int test_case=0;test_case<T;test_case++){
        li.clear();
        
        string p;
        cin >> p;

        int n;
        cin >> n;

        string s;
        cin >> s;

        string num;
        for(int i=1;i<s.size()-1;i++){
            if(s[i] == ','){
                li.push_back(stoi(num));
                num = "";
            }else num += s[i];
        }
        if(num != "")
            li.push_back(stoi(num));

        bool reverse = false;
        bool error = false;
        for(int i=0;i<p.size();i++){
            if(p[i] == 'R')
                reverse ^= true;
            else if(p[i] == 'D'){
                if(li.empty()){
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                else if(reverse == false)
                    li.pop_front();
                else if(reverse == true)
                    li.pop_back();
            }
        }
        
        if(error)
            continue;

        cout << "[";
        if(li.empty());
        else if(reverse == false){
            auto iter = li.begin();
            cout << *iter;
            for(iter++; iter != li.end(); iter++)
                cout << "," << *iter;    
        }
        else{
            auto iter = li.rbegin();
            cout << *iter;
            for(iter++; iter != li.rend(); iter++)
                cout << "," << *iter;
        }
        
        cout << "]\n";
    }
    return 0;
}