#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define ALPHA_COUNT (26)

int solution(string name) 
{
    int answer = 0;
    string init;
    for (int i = 0; i < name.size(); i++) {
        init.push_back('A');
    }    

    size_t current = 0;
    size_t next;
    int r_temp_idx;
    int l_temp_idx;
    int temp;
    int r_count;
    int l_count;
    while (init.compare(name) != 0) {
        if (init[current] != name[current]) {
            temp = name[current] - init[current];
            if (temp > 13) {
                answer += ALPHA_COUNT - temp;
                init[current] = name[current];
            } else {
                answer += temp;
                init[current] = name[current];
            }
        } else {
            //find next index
            r_count = 0;
            l_count = 0;
            r_temp_idx = (current + 1) % name.size();
            r_count++;
            while (r_temp_idx != current) {
                if (init[r_temp_idx] != name[r_temp_idx]) {
                    break;
                } 
                r_count++;
                r_temp_idx = (r_temp_idx + 1) % name.size();
            }
            if (r_temp_idx == current) {
                break;
            }            

            l_temp_idx = current - 1;
            l_count++;
            if (l_temp_idx < 0) {
                l_temp_idx = name.size() - 1;
            }
            while (l_temp_idx != current) {
                if (init[l_temp_idx] != name[l_temp_idx]) {
                    break;
                }
                l_count++;
                l_temp_idx--;
                if (l_temp_idx < 0) {
                    l_temp_idx = name.size() - 1;
                }
            }

            if (r_count > l_count) {
                next = l_temp_idx;
                answer += l_count;
            } else if (r_count < l_count) {
                next = r_temp_idx;
                answer += r_count;
            } else {
                //같을 때 수정이 필요함.
                next = r_temp_idx;
                answer += r_count;
            }
            current = next;
        }
    } 
    return answer;
}

int main(void)
{
    cout << solution("BBBAAAB") << endl;
    return 0;
}
