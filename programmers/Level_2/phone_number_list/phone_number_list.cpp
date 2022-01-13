#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    vector<string>::size_type i;
    vector<string>::size_type k;
    sort(phone_book.begin(), phone_book.end());
    for (i = 0; i < phone_book.size() - 1; ++i) {
        for (k = 0; k < phone_book[i].size(); ++k) {
            if (phone_book[i][k] != phone_book[i + 1][k]) {
                answer = true;
                break;
            }
            answer = false;
        }
        if (!answer) {
            goto exit;
        }
    }
exit:
    return answer;
}

int main(void)
{
    cout << solution({"119", "97674223", "1195524421"}) << endl;
    cout << solution({"123","456","789"}) << endl;
    cout << solution({"12","123","1235","567","88"}) << endl;
    return 0;
}
