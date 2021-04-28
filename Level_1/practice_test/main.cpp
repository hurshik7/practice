#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer_vector;
    vector<int> s1 = {1, 2, 3, 4, 5};
    vector<int> s2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> s3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int>::size_type i;
    vector<int>::iterator it1 = s1.begin();
    vector<int>::iterator it2 = s2.begin();
    vector<int>::iterator it3 = s3.begin();
    int sc1 = 0;
    int sc2 = 0;
    int sc3 = 0;
    int answer;
    for (i = 0; i < answers.size(); i++) {
        answer = answers[i];
        if (answer == *it1++) {
            sc1++;
        } 
        if (answer == *it2++) {
            sc2++;
        }
        if (answer == *it3++) {
            sc3++;
        }
    
        if (it1 == s1.end()) {
            it1 = s1.begin();
        }
        if (it2 == s2.end()) {
            it2 = s2.begin();
        }
        if (it3 == s3.end()) {
            it3 = s3.begin();
        }
    }
    
    int max = sc1;
    answer_vector.push_back(1);
    if (sc2 > max) {
        max = sc2;
        answer_vector.clear();
        answer_vector.push_back(2);
    } else if (sc2 == max) {
        answer_vector.push_back(2);
    }

    if (sc3 > max) {
        answer_vector.clear();
        answer_vector.push_back(3);
    } else if (sc3 == max) {
        answer_vector.push_back(3);
    }
     
    return answer_vector;
}

int main(void)
{
    vector<int> v = {1, 3, 2, 4, 2};
    vector<int> sol = solution(v);
    vector<int>::size_type i;
    for (i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
    return 0;
}
