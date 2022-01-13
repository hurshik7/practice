#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    int count;
    for (int i = 0; i < prices.size() - 1; i++) {
        count = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                count++;
                break;  
            }
            count++; 
        }
        answer.push_back(count);
    }
    answer.push_back(0);    
    return answer;
}

int main(void)
{
    for (auto i : solution({1, 2, 3, 2, 3, 1})) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
