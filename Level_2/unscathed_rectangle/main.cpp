#include <iostream>
#include <cmath>

using namespace std;

long long solution(int w,int h) 
{
	long long answer = w * h;
	double y_prev = 0;

	for	(int i = 1; i < w + 1; i++) 
	{
		double y_now = static_cast<long long>(i) * static_cast<long>(h) / static_cast<double>(w);
		answer -= ceil(y_now) - floor(y_prev);
		y_prev = y_now;
	}

	return answer;
}

int main(void)
{
	cout << solution(4, 5) << endl;
	return 0;
}

