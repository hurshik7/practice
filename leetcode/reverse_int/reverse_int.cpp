#include <limits>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        
        bool isNeg = false;
        if (x < 0) {
            isNeg = true;
            x = abs(x);
        }
        
        stack<int> st;
        int digitCount = 0;
        while (x > 0) {
            st.push(x % 10);
            x = x / 10;
            digitCount++;
        }
        if (digitCount > 10) {
            return 0;
        }
        
        long ret = 0;
        for (int i = 0; i < digitCount; i++) {
            long temp = (long)(st.top() * pow(10.0, i));
            ret += temp;
            if (!((INT_MIN <= ret) && (ret <= INT_MAX))) {
                return 0;
            }
            st.pop();
        }
        
        if (isNeg == true) {
            return (-ret);
        }
        
        return ret;
    }
};
