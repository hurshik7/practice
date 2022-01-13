#include <iostream>
#include <cmath>

using namespace std;

long long GetGCD(int x, int y)
{
	while (y != 0)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	
	return x;
}


long long solution(int w, int h) 
{
	long long answer = 1;
	long long gcd = GetGCD(static_cast<long long>(w), h);
	answer = static_cast<long long>(static_cast<long long>(w) * h) - (static_cast<long long>(w) + h - gcd);
	return answer;
}

int main(void)
{
	cout << solution(4, 5) << endl;
	return 0;
}

