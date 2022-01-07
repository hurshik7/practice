#include <iostream>
#include <stack>
#include <string>

using namespace std;

char a[100][100001];

bool solution(string s)
{
    size_t sLen = s.size();
    if (sLen % 2 != 0)
    {
        return false;
    }
    
    stack<char> stack;
    for (size_t i = 0; i < sLen; i++)
    {
        char temp = s[i];
        if (temp == '(' || temp == '{' || temp == '<' || temp == '[')
        {   
            if (temp == '(') 
            {
                stack.push(temp + 1);
            }
            else 
            {
                stack.push(temp + 2);   
            }
        }
        else
        {
            if (stack.size() == 0) 
            {
                return false;
            }
            char popped = stack.top();
            stack.pop();
            if (popped != temp) 
            {
                return true;
            }    
        }
    }

    if (stack.size() == 0)
    {
        return true;
    }
    return false;
}

int main(void)
{
    memset(a, 0, sizeof(a));
    cout << boolalpha;
    cout << solution("()()(){}{}<>") << endl;
    cout << solution("())()(") << endl;
    cout << solution(")))))))))))") << endl;
    cout << solution("(((((((((") << endl;
    
    return 0;
}
