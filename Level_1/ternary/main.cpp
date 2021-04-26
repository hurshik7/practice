#include <iostream>
#include <string>
#include <vector>

using namespace std;

int my_pow(int n, int count) 
{
    int ret = 1;
    if (count == 0) {
        return 1;
    }
    for (int i = 0; i < count; i++) {
        ret *= n;
    }
    return ret;
}

int solution(int n) 
{
    int answer = 0;
    int temp = n;
    string ternary = "";

    while (temp != 0) {
        ternary.push_back((temp % 3) + '0');                
        temp = temp / 3;
    }

    temp = 0;
    string::reverse_iterator riter;
    for (riter = ternary.rbegin(); riter != ternary.rend(); riter++) {
        answer += (*riter - '0') * my_pow(3, temp);
        temp++; 
    }  
    return answer;
}

int main(void)
{
    cout << solution(45) << endl; 
    return 0;
}
