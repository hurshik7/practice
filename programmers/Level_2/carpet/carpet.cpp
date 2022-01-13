#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int area = brown + yellow;
    set<int> measure;

    for (int i = 1; i * i <= area; i++) {
        if (area % i == 0) {
            measure.insert(i);
            measure.insert(area / i);
        }
    }
 
    set<int>::iterator it_1 = measure.begin();
    set<int>::iterator it_2 = measure.end();
    it_2--;
    while (it_1 != it_2) {
        if ((*it_2 - 2) * (*it_1 - 2) == yellow) {
            answer.push_back(*it_2);
            answer.push_back(*it_1);
            break;
        }
        it_1++;
        it_2--;
    }   
    if (answer.empty()) {
        answer.push_back(*it_1);
        answer.push_back(*it_1);
    } 
    return answer;
}

int main(void)
{
    for (int i : solution(24, 24)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
