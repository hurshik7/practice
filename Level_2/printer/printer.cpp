#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;
    vector<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push_back(make_pair(i, priorities[i]));
    }

    int j;
    pair<int, int> temp;
    while (q.size() > 0) {
        j = q.front().second;
        for (int i = 0; i < q.size(); i++) {
            if (j < q[i].second) {
                temp = q.front();
                q.erase(q.begin());
                q.push_back(temp);
                goto update; 
            }
        }
        if (location == q.front().first) {
            answer++;
            break;
        } else {
            q.erase(q.begin());
            answer++;
        }
update:
        continue;
    }
     
    return answer;
}
 

int main(void)
{
    cout << solution({2, 1, 3, 2}, 2) << endl;
    cout << solution({1, 1, 9, 1, 1, 1}, 0) << endl;
    return 0;
}
