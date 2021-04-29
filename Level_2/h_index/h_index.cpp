#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    int h = citations[0];
    int count = 0;
    while (h > 0) {
        count = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) {
                count++;
            }
        }
        if (count >= h) {
            answer = h;
            break;
        }
        h--;
    }
    return answer;
}

int main(void)
{
    cout << solution({3, 0, 6, 1, 5}) << endl;
    cout << solution({4, 3, 5, 6, 2, 1, 0, 0}) << endl;
    cout << solution({1, 1, 1, 1, 1,}) << endl;
    cout << solution({22, 1, 1, 1, 1, 1}) << endl;
    cout << solution({2, 2, 44, 3, 4, 5, 3, 2, 1, 3, 4, 4, 4}) << endl;
    return 0;
}

