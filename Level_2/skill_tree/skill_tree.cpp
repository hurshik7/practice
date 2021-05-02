#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = (int)skill_trees.size();
    vector<string>::size_type i;
    vector<string>::size_type j;
    int idx;
    int temp;
    bool is_skill;
    for (i = 0; i < skill_trees.size(); ++i) {
        idx = -1;
        temp = -1;
        is_skill = false;
        for (j = 0; j < skill_trees[i].size(); ++j) {
            temp = skill.find(skill_trees[i][j], 0);
            if (temp != string::npos) {
                is_skill = true;
                if (temp != idx + 1) {
                    idx = -1;
                    break;
                } else {
                    idx = temp;
                }   
            }
        }
        if (is_skill && idx == -1) {
            answer--;
        }
    }
    
    return answer;
}

int main(void)
{
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}) << endl;
    return 0;
}
