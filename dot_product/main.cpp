#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a, vector<int> b) 
{
    int answer = 0;
    for (vector<int>::size_type i = 0; i < a.size(); i++) {
        answer += a[i] * b[i];
    }
    return answer;
}

int main(void)
{
    cout << solution({1, 2, 3, 4}, {-3, -1, 0, 2}) << endl;
    cout << solution({-1, 0, 1}, {1, 0, -1}) << endl;
    return 0;
}
