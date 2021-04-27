#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

        }
    }   

 
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


int main(void)
{
    for (auto i : solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}})) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
