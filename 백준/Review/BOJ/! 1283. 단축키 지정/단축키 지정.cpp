#include <iostream>
#include <cctype>

using namespace std;

bool alphas[26];

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    cin.ignore();
    for(int i=0;i<N;i++){
        string option;
        getline(cin,option);

        bool set = false;
        int idx = 0;
        if(alphas[toupper(option[idx]) - 'A'] == false){
            alphas[toupper(option[idx]) - 'A'] = true;
            set = true;
        }
        
        if(set == false){
            idx = 0;
            while(idx < option.size()){
                if(option[idx++] == ' '){
                    if(alphas[toupper(option[idx]) - 'A'] == false){
                        alphas[toupper(option[idx]) - 'A'] = true;
                        set = true;
                        break;
                    }                    
                }
            }
        }

        if(set == false){
            for(idx=0;idx<option.size();idx++){
                if(option[idx] == ' ')
                    continue;
                if(alphas[toupper(option[idx]) - 'A'] == false){
                    alphas[toupper(option[idx]) - 'A'] = true;
                    set = true;
                    break;
                }   
            }
        }

        if(set == false)
            cout << option << "\n";
        else{
            for(int j=0;j<option.size();j++){
                if(j == idx)
                    cout << "[" << option[j] << "]";
                else
                    cout << option[j];
            }            
            cout << "\n";
        }
    }
    return 0;
}