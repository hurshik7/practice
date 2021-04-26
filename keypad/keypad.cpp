#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[5][4] = {{1, 2, 3, 4}, {2, 1, 2, 3}, {3, 2, 1, 2}, {4, 3, 2, 1}, {3, 2, 1, 0}};

int get_distance(int pos, int des)
{
    int ret;
    int convert_des;
    int convert_pos;
    bool is_middle = false;
    if (pos == 0) {
        convert_pos = 4;
    } else if (pos == -1) {
        convert_pos = 3;
    } else {
        if (pos == 3 || pos == 6 || pos == 9) {
            convert_pos = (pos / 3) - 1;
        } else if (pos == 1 || pos == 4 || pos == 7) {
            convert_pos = pos / 3;
        } else {
            is_middle = true;
            convert_pos = pos / 3;
        }
    }

    if (des == 0) {
        convert_des = 3;
    } else {
        convert_des = des / 3;
    }
    ret = d[convert_pos][convert_des];
    if (is_middle) {
        ret--;
    }
    return ret; 
}   

string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    vector<int>::size_type i;
    int num;
    int left_pos = -1;
    int right_pos = -1;
    int left_d = 0;
    int right_d = 0;

    for (i = 0; i < numbers.size(); i++) {
        num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            answer.push_back('L');
            left_pos = num;
        } else if (num == 3 || num == 6 || num == 9) {
            answer.push_back('R');
            right_pos = num;
        } else {
            left_d = get_distance(left_pos, num);
            right_d = get_distance(right_pos, num);
            if (left_d < right_d) {
                answer.push_back('L');
                left_pos = num;
            } else if (right_d < left_d) {
                answer.push_back('R');
                right_pos = num;
            } else {
                if (hand[0] == 'r') {
                    answer.push_back('R');
                    right_pos = num;
                } else {
                    answer.push_back('L');
                    left_pos = num;
                }
            }
        }
    }

    return answer;
}

int main(void) 
{
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;
    cout << solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left") << endl;
    cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right") << endl;
    return 0;
}
