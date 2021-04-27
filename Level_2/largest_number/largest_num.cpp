#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

//string을 비교하면 편하다.
string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> num;
    for (auto i : numbers) {
        num.push_back(to_string(i));
    }
    sort(num.begin(), num.end(), cmp);
    if (num[0] == "0") {
        return "0";
    }

   for (auto j : num) {
        answer += j;
    }
    
    return answer;
}

int main(void)
{
    cout << solution({6, 10, 2}) << endl;
    cout << solution({3, 30, 34, 5, 9}) << endl;
    return 0;
}
