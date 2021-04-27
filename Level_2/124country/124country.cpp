#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) 
{
    string answer = "";
    vector<int> num = {4, 1, 2};
    int i;
    
    while (n > 0) {
        i = n % 3;
        answer.insert(answer.begin(), num[i] + '0');
        n = n / 3.0000001; 
    }
    
    return answer;
}
int main(void)
{   
    for (int i = 1; i < 100; i++) {
        cout << i << " : " << solution(i) << endl;
    }
    return 0;
}
