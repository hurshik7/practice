#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    int i;
    int j;
    while (pq.top() < K) {
        if (pq.size() == 1) {
            answer = -1;
            break;
        }
        i = pq.top();
        pq.pop();
        j = pq.top();
        pq.pop();
        pq.push(i + 2 * j);
        answer++;
    }
 
    return answer;
}

int main(void)
{
    cout << solution({1, 2, 3, 9, 10, 12}, 7) << endl;
    return 0;
}
