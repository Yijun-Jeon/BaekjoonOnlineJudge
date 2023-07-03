#include <iostream>
#include <numeric>
using namespace std;
#define MAX_NUM 1000

int main(void)
{
    int N;
    double scores[MAX_NUM] = {};
    double maxScore = 0.0f;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> scores[i];
        maxScore = scores[i] > maxScore ? scores[i] : maxScore;
    }
    for (int i = 0; i < N; i++)
        scores[i] = scores[i] / maxScore * 100;

    cout << (double)accumulate(scores, scores + N, 0.0f) / N << endl;
    return 0;
}
