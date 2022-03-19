class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) {
            while (b.length() != a.length()) {
                b.insert(0, 1, '0');
            }
        }
        else if (a.length() < b.length()) {
            while (b.length() != a.length()) {
                a.insert(0, 1, '0');
            }
        }
        
        int carry = 0;
        string ret = "";
        for (int i = a.length() - 1; i >= 0; --i) {
            int calc = (a[i] - '0') + (b[i] - '0') + carry;
            if (calc == 2) {
                ret.push_back('0');
                carry = 1;
            } else if (calc == 1) {
                ret.push_back('1');
                carry = 0;
            } else if (calc == 3) {
                ret.push_back('1');
                carry = 1;
            } else {
                ret.push_back('0');
                carry = 0;
            }
        }
        if (carry == 1) {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};

