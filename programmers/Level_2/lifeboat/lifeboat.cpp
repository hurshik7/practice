#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    int w = 0;
    int first = 0;
    int second = (int)people.size() - 1;
    sort(people.begin(), people.end(), greater<int>());
    while (first <= second) {
        w += people[first];
        if (w + people[second] <= limit) {
            second--;
        }
        first++;
        answer++;
        w = 0;
    }
    return answer;
}

int main(void)
{
    cout << solution({70, 50, 80, 50}, 100) << endl;
    cout << solution({70, 80, 50}, 100) << endl;
    return 0;
}
