#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    
    vector<int>::size_type i;
    vector<int>::size_type j;
    size_t zero_count = 0;
    size_t correct_count = 0;
    for (i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            zero_count++;
            continue;
        }
        for (j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                correct_count++;
                win_nums.erase(win_nums.begin() + j);
            }
        }
    }

    int score = 6 - correct_count - zero_count + 1;
    if (score == 7) {
        answer.push_back(6);
    } else {
        answer.push_back(score);   
    }
    
    if (correct_count == 0) {
        answer.push_back(6);
    } else {
        answer.push_back(6 - correct_count + 1);
    }
    return answer;
}

int main(void)
{
    vector<int> sol1 = solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19});
    for (int i = 0; i < sol1.size(); i++) {
        cout << sol1[i] << " ";
    }
    cout << endl;
    return 0;
}
