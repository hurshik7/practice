#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) 
{
    int count = 0;
    bool is_erase = false;
    while (count != k) {
        for (int i = 0; i < number.size(); i++) {
            if (number[i] < number[i + 1]) {
                number.erase(number.begin() + i);
                count++;
                is_erase = true;
                break;
            }
        }
        if (!is_erase) {
            number.pop_back();
            count++;
            is_erase = false;
        }
    }

    return number;
}

int main(void)
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
    return 0;
}
