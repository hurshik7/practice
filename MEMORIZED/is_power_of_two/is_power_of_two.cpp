#include <iostream>

using namespace std;

bool is_power_of_two(unsigned int num)
{
	return ((num & (num - 1)) == 0);
}

int main(void)
{
	cout << is_power_of_two(64) << endl;
	cout << is_power_of_two(128) << endl;
	cout << is_power_of_two(1) << endl;
	cout << is_power_of_two(1024) << endl;
	cout << is_power_of_two(16) << endl;
	cout << is_power_of_two(32) << endl;
	cout << is_power_of_two(123456) << endl;
	cout << is_power_of_two(12) << endl;
	cout << is_power_of_two(11234) << endl;
	cout << is_power_of_two(1566) << endl;
	cout << is_power_of_two(20) << endl;
	cout << is_power_of_two(2048) << endl;
	return 0;
}
