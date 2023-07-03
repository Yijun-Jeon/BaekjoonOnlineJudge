#include <iostream>
using namespace std;

float getScore(int credit, string score){
    float result;
    switch (score[0])
    {
    case 'A':
        result = 4.0;
        break;
    case 'B':
        result = 3.0;
        break;
    case 'C':
        result = 2.0;
        break;
    case 'D':
        result = 1.0;
        break;    
    default:
        result = 0.0;
    }
    if(score.length() > 1 && score[1] == '+')
        result += 0.5;
    return credit * result;
}

int main(void)
{
    float sum = 0.0;
    int cnt = 0;

    for(int i=0;i<20;i++){
        string lecture, score;
        float credit;

        cin >> lecture >> credit >> score;
        sum += getScore(credit,score);
        if(score != "P")
            cnt += credit;
    }
    cout << sum / cnt << endl;
    return 0;
}