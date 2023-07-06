#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string s1, string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    else
        return s1.length() < s2.length();
}

int main(void)
{
    int N;
    cin >> N;

    vector<string> words;
    for(int i=0;i<N;i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(),words.end(),comp);
    words.erase(unique(words.begin(),words.end()),words.end());

    for(int i=0;i<words.size();i++)
        cout << words[i] << endl;

    return 0;
}