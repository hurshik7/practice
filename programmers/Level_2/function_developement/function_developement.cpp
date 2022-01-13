#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    vector<int>::size_type i;
    vector<int>::size_type current = 0;
    size_t complete_count;    

    while (current < progresses.size()) {
        for (i = current; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        
        complete_count = 0;
        if (progresses[current] >= 100) {
            complete_count++;
            for (i = current + 1; i < progresses.size(); i++) {
                if (progresses[i] < 100) {
                    break;
                }
                complete_count++;
            }
            current = i;
            answer.push_back(complete_count);
        }
    }

    return answer;
}

int main(void)
{
    for (auto i : solution({93, 30, 55}, {1, 30, 5})) {
        cout << i << " ";
    }    
    cout << endl;
    for (auto j : solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1})) {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}


