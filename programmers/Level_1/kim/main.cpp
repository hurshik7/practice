#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    size_t index;
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i].compare("Kim") == 0) {
            index = i;
        }
    }
    answer.append("김서방은 ");
    answer.append(to_string(index));
    answer.append("에 있다");
    return answer;
}

int main(void)
{
    cout << solution({"Jane", "Kim"}) << endl;
    return 0;
}
