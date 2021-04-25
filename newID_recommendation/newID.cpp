#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

string solution(string new_id) 
{
    string answer;
    char current;

    string::size_type i;
    for (i = 0; i < new_id.size(); i++) {
        current = new_id[i];
        
        //1
        if ('A' <= current && current <= 'Z') {
            current += 32;
            new_id[i] = current;
            answer.push_back(current);
            continue;
        }
        
        //2
        if (('a' > current || current > 'z') && ('0' > current || current > '9') && current != '-' && current != '_' && current != '.') {
            continue;
        }  
    
        //3
        if (current == '.') {
            if (answer.back() != '.') {
                answer.push_back(current);
                i++;
                while (new_id[i] == '.' && i < new_id.size()) {
                    i++;
                }
                if (i >= new_id.size() ) {
                    break;
                }
                i--;
            }
            continue;
        }            
        answer.push_back(current);
    }
   
    //4
    if (answer[0] == '.') {
        answer.erase(answer.begin());
    }
    if (answer[answer.size() - 1] == '.') {
        answer.pop_back();
    }


    //5
    if (answer.empty()) {
        answer.push_back('a');
    }

    //6
    if (answer.size() >= 16) {
        answer.erase(answer.begin() + 15, answer.end());
    }
    if (answer.back() == '.') {
        answer.pop_back();
    }
    
    //7
    if (answer.size() <= 2) {
        while (answer.size() < 3) {
            answer.push_back(answer.back());
        }
    }

    return answer;
}


int main(void) 
{
    assert(solution("...!@BaT#*..y.abcdefghijklm") == "bat.y.abcdefghi");
    assert(solution("z-+.^.") == "z--");
    assert(solution("=.=") == "aaa");
    assert(solution("123_.def") == "123_.def");
    cout << solution("abcdefghijklmn.p") << endl;
    assert(solution("abcdefghijklmn.p") == "abcdefghijklmn");
    return 0;
}
