#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 0;
    map<string, int> m;

    for (vector<vector<string>>::size_type i = 0; i < clothes.size(); i++) {
        if (m.find(clothes[i][1]) == m.end()) {
            m[clothes[i][1]] = 1;
        } else {
            m[clothes[i][1]] = m[clothes[i][1]] + 1;
        }
    }
    
    int temp = 1;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        temp *= (it->second + 1);
    }
    answer = temp - 1;
    return answer;
}

int main(void)
{
    cout << solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;
    cout << solution({{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}) << endl;
    cout << solution({{"a","aa"}, {"b","aa"}, {"c","aa"}, {"aa","bb"}, {"bb","bb"}, {"c_c","bb"}, {"aaa","cc"}, {"bbb","cc"}, {"ccc","cc"}}) << endl;
    return 0;
}

