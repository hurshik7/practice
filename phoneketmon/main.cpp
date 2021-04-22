#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int>::size_type i;    
    int max = nums.size() / 2;
    int temp = 0;

    sort(nums.begin(), nums.end());
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] != temp) {
            temp = nums[i];
            answer++;
        }
    }
    
    if (answer > max) {
        answer = max;
    }
    
    return answer;
}

int main(void)
{
    cout << solution({3, 1, 2, 3}) << endl;
    cout << solution({3, 3, 3, 2, 2, 4}) << endl;
    cout << solution({3, 3, 3, 2, 2, 2}) << endl;
    return 0;
}
