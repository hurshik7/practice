#include <string>
#include <sstream>
#include <iostream>

using namespace std;

bool is_number(char chr)
{
    return '0' <= chr && chr <= '9';
}


int solution(string dartResult) 
{
    int answer = 0;
    int num;
    string::size_type next = 0;
    string::size_type i;
    char temp;
    char bonus;
    char option = '\0';
    int before_round = 0;

    for (int j = 0; j < 3; j++)
    {
        num = dartResult[next++] - '0';
        option = '\0';
        if (dartResult[next] == '0') {
            num = 10;
            next++;
        }
        for (i = next; !is_number(dartResult[i]) && i < dartResult.size(); i++) 
        {
            temp = dartResult[i];
            if (temp == '0') 
            {
                num = 10;
            }
            else if (temp == 'S' || temp == 'D' || temp == 'T') 
            {
                bonus = temp;
            } else {
                option = temp;
            }   
        }

        if (bonus == 'D') 
        {
            num = num * num;
        } else if (bonus == 'T') 
        {
            num = num * num * num;
        }  

        if (option != '\0')
        {
            if (option == '*') 
            {
                answer += before_round;
                num = 2 * num;
            } else 
            {
                num = -num;
            }
        } 
    
        answer += num;
        before_round = num;  
        next = i;
    }

    return answer;    
}

int main(void)
{
    cout << solution("1D2S0T") << endl;
    return 0;
}
