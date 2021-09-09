#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string word) 
{
    int answer = 0;
	int mul = 781;
	char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (vowels[j] == word[i])
			{
				answer += 1 + j * mul;
			}
		}
		mul = (mul - 1) / 5;
	}
		
    return answer;
}

int main(void)
{
	cout << solution("AAAAE") << endl;
	cout << solution("AAAE") << endl;
	cout << solution("I") << endl;
	cout << solution("EIO") << endl;
	return 0;
}
