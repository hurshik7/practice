#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer(n);
    int temp;
    for (int i = 0; i < n; i++) {
        temp = arr1[i] | arr2[i];
        while (temp != 0) {
            if (temp % 2 == 1) {
                answer[i].insert(answer[i].begin(), '#');
            } else {
                answer[i].insert(answer[i].begin(), ' ');
            }
            temp /= 2;
        }
        while ((int)answer[i].size() < n) {
            answer[i].insert(answer[i].begin(), ' ');
        }
    }

    return answer;
}

int main(void)
{
    vector<int> arr1 = {46, 33, 33, 22, 31, 50};
    vector<int> arr2 = {27, 56, 19, 14, 14, 10};
    vector<string> answer = solution(6, arr1, arr2);
    for (vector<string>::size_type i = 0; i < 6; i++) {
        cout << answer[i] << endl;
    }     
    return 0;
}
