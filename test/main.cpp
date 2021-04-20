#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    stack<int> bucket;
    int target;
    int character;

    for (int i = 0; i < (int)moves.size(); i++) {
        target = moves[i] - 1;
        for (int j = 0; j < (int)board[0].size(); j++) {
            character = board[j][target];
            if (character != 0) {
                board[j][target] = 0;
                if (bucket.empty()) {
                    bucket.push(character);
                    break;
                }
                if (character == bucket.top()) {
                    bucket.pop();
                    answer++;
                } else {
                    bucket.push(character);
                }
                break;
            }
        }
    }

    return answer*2;
}

int main(void)
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    cout << solution(board, moves) << endl;
    return 0;
}
