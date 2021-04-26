#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    int helping_student;
    
    for (vector<int>::size_type i = 0; i < lost.size(); i++) {
        for (vector<int>::size_type j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
            }
        }
    }    

    for (vector<int>::size_type i = 0; i <reserve.size(); i++) {
        helping_student = reserve[i];
        for (vector<int>::size_type j = 0; j < lost.size(); j++) {
            if (lost[j] == helping_student - 1 || lost[j] == helping_student + 1) {
                lost.erase(lost.begin() + j);
                break;
            } else if (lost[j] == helping_student) {
                lost.erase(lost.begin() + j);
                break;
            }
        }
    }
    answer = n - (int)lost.size();
    return answer;
}

int student[35];
int solution_reference (int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}

int main(void)
{
    cout << solution(5, {2, 4}, {1, 3, 5}) << endl;
    cout << solution(5, {2, 4}, {3}) << endl;
    cout << solution(3, {3}, {1}) << endl;
    cout << solution(5, {1, 2, 3}, {2, 3, 4}) << endl;
    cout << solution(2, {1, 2}, {2, 1}) << endl;
    return 0;
}
