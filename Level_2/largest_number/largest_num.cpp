#include <string>
#include <vector>
#include <iostream>

using namespace std;

string num_to_string(int num)
{
    string ret;
    int temp;
    while (num != 0) {
        temp = num % 10;
        ret.insert(ret.begin(), temp + '0');
        num /= 10;
    }
    return ret;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    int temp;
    int max_idx;
    int max = -1;
    vector<int> digits(numbers);

    while (numbers.size() > 0) {
        max = -1;
        for (int i = 0; i < numbers.size(); i++) {
            temp = numbers[i];
            while (temp >= 10) {
                temp /= 10;
            }
            if (temp >= max) {
                max_idx = i;
                max = temp;
            }
        }
        answer.append(num_to_string(numbers[max_idx]));
        numbers.erase(numbers.begin() + max_idx);
    }
    return answer;
}

int main(void)
{
    cout << solution({6, 10, 2}) << endl;
    cout << solution({3, 30, 34, 5, 9}) << endl;
    return 0;
}
