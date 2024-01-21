#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> wordsVec, wordsVecReverse;

bool comp(string s1, string s2){
    if(s1.size() < s2.size())
        return true;
    
    if(s1.size() == s2.size())
        return s1 < s2;
    
    return false;
}

int binarySearch(string s){
    vector<string> *targetVec = &wordsVec;
    if(s[0] == '?'){
        targetVec = &wordsVecReverse;
        reverse(s.begin(),s.end());
    }
    
    string startS = s, endS = s;  
    for(int i=0;i<s.size();i++){
        if(s[i] == '?'){
            startS[i] = 'a';
            endS[i] = 'z';
        }
    }
    
    int end = upper_bound(targetVec->begin(),targetVec->end(),endS,comp) - targetVec->begin();
    int start = lower_bound(targetVec->begin(),targetVec->end(),startS,comp) - targetVec->begin();
    return end - start;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    wordsVec = words;
    for(int i=0;i<words.size();i++){
        reverse(words[i].begin(),words[i].end());
        wordsVecReverse.push_back(words[i]);
    }
    
    sort(wordsVec.begin(),wordsVec.end(),comp);
    sort(wordsVecReverse.begin(),wordsVecReverse.end(),comp);
    
    for(int i=0;i<queries.size();i++)
        answer.push_back(binarySearch(queries[i]));
    
    return answer;
}