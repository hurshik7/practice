#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    int w = 0;
    int next = 0;
    int current = 0;
    int n = 0;
    vector<int> d(truck_weights.size(), 0);

    while (n < truck_weights.size()) {        
        for (int j = current; j < next; j++) {
            if (d[j] == bridge_length) {
                w -= truck_weights[j];
                d[j] = -1;
                n++;
                current = j + 1; 
            }
        } 

        for (int i = next; i < truck_weights.size(); i++) {
            if (w + truck_weights[i] <= weight) {
                w += truck_weights[i];
                next = i + 1;
                break;
            } else {
                next = i;
                break;
            }
        }

        for (int i = current; i < next; i++) {
            d[i]++;
        } 

        answer++;
    } 
    return answer;
}

int main(void)
{
    cout << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << solution(100, 100, {10}) << endl;
    cout << solution(100, 100, {10,10,10,10,10,10,10,10,10,10}) << endl;    
    return 0;
}
