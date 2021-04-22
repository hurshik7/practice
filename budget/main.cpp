#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    vector<int>::size_type dsize = d.size();
    sort(d.begin(), d.end());
    int i;    

    int max_count = 0;
    answer = dsize;
    int temp;
    while (answer > 0) {
        temp = 0;
        for (i = 0; i < answer; i++) {
            temp += d[i];
        }

        if (temp <= budget) {
            if (max_count < answer) {
                max_count = answer;
            } else {
                break;
            }
        }
        answer--;
    }    
    answer = max_count;
    return answer;
}

int main(void)
{
    cout << solution({1, 3, 2, 5, 4}, 9) << endl;
    cout << solution({2, 2, 3, 3}, 10) << endl;
    return 0;
}
