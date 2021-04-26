#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
void printVector(vector<T> vec);

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<double> count_of_players(N + 1, 0);
    // 0이 1번 스테이지
    
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 0; j < stages[i]; j++) {
            count_of_players[j]++;
        }
    }
 

    for (int j = 0; j < N; j++) {
        if (count_of_players[j] == 0) {
            continue;
        }
        count_of_players[j] = (count_of_players[j] - count_of_players[j + 1]) / count_of_players[j];
    }
    count_of_players.pop_back();
 
    
    int max_idx; 
    while (answer.size() < N) {
        max_idx = max_element(count_of_players.begin(), count_of_players.end()) - count_of_players.begin();
        answer.push_back(max_idx + 1);
        *(max_idx + count_of_players.begin()) = -1;
    }
     
    return answer;
}

template <typename T>
void printVector(vector<T> vec)
{
    int i;
    for (i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    vector<int> sol = solution(5, {2, 1, 2, 4, 2, 4, 3, 3});
    printVector(sol);
    return 0;
}

