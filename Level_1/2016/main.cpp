#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b)
{
    string answer = "";
    int days = 0;
    for (int i = 1; i < a; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            days += 31;
        } else if (i == 2) {
            days += 29;
        } else {
            days += 30;
        }
    }
    days += b;
    days -= 1;
    days = days % 7;
    switch (days) {
    case 0:
        answer = "FRI";
        break;
    case 1:
        answer = "SAT";
        break;
    case 2:
        answer = "SUN";
        break;
    case 3:
        answer = "MON";
        break;
    case 4:
        answer = "TUE";
        break;
    case 5:
        answer = "WED";
        break;
    case 6:
        answer = "THU";
        break;
    default:
        break;
    }
    
    return answer;
}

int main(void)
{
    cout << solution(5, 24) << endl;
    return 0;
}
