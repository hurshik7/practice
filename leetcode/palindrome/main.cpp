#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    const char* cStrInput = s.c_str();
	const char* start = cStrInput;
    const char* end = start + s.size() - 1;
  
    while (start < end) {
  	    char start_temp = *start;
        char end_temp = *end;
  	    if ((start_temp < 'A' || 'Z' < start_temp) && (start_temp < 'a' || 'z' < start_temp)) {
            start++;
            continue;
        }
        if ((end_temp < 'A' || 'Z' < end_temp) && (end_temp < 'a' || 'z' < end_temp)) {
            end--;
            continue;
        }
    
        if ('A' <= start_temp && start_temp <= 'Z') {
    	    start_temp |= 0x20;
        }
    
        if ('A' <= end_temp && end_temp <= 'Z') {
    	    end_temp |= 0x20;
        }

		if (start_temp != end_temp) {
    	    return false;
        }
		start++;
        end--;
  }
  
  return true;
}

int main(void)
{
    cout << isPalindrome("ABBA") << endl;
    cout << isPalindrome("a") << endl;
    cout << isPalindrome("Yel ,, : l leY") << endl;
    cout << isPalindrome("AB") << endl;
    cout << isPalindrome("AAAAAAAAAAAA") << endl;
    cout << isPalindrome("Yel ,.,.,. lley") << endl;
}
