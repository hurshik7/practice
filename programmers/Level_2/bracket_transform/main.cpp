#include <string>
#include <vector>
#include <iostream>

using namespace std;

size_t Divide_String_Index(string p);

string solution(string p) 
{
	size_t pLength = p.size();
    string answer = "";
	if (pLength == 0)
	{
		return answer;	
	}

		
	size_t index = Divide_String_Index(p);
	string u = p.substr(0, index);
	string v = p.substr(index, pLength - index); 		

	if (u[0] == '(')
	{
		return (u + solution(v));		
	}
	else 
	{
		answer.push_back('(');
		answer += solution(v);
		answer.push_back(')');
		u.pop_back();
		u.erase(0, 1);
		for (size_t k = 0; k < u.size(); k++)
		{
			if (u[k] == '(') 
			{
				u[k] = ')';
			}
			else if (u[k] == ')')
			{
				u[k] = '(';
			}
		}		
		answer += u;
	}

    return answer;
}

size_t Divide_String_Index(string p)
{
	char firstChar = p[0];
	size_t count = 1;
	size_t i;
	for (i = 1; i < p.size(); i++)
	{
		if (p[i] == firstChar)
		{
			count++;
		}
		else 
		{
			count--;
		}

		if (count == 0)
		{
			break;
		}
	}

	return i + 1;
}

int main(void)
{
	cout << solution("(()())()") << endl;
	return 0;
}
