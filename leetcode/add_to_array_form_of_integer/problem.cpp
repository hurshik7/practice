class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        int carry = 0;
        while (k > 0 && i >= 0) {
            int digit = k % 10;
            num[i] += (digit + carry);
            if (num[i] > 9) {
                carry = 1;
                num[i] -= 10;
            }
            else {
                carry = 0;
            }
            
            i--;
            k /= 10;
        }
        while (i >= 0) {
             num[i] += carry;
            if (num[i] > 9) {
                carry = 1;
                num[i] -= 10;
            }
            else {
                carry = 0;
            }
            
            i--;
        }
        
        while (k > 0) {
            int digit = k % 10;
            digit += carry;
            if (digit > 9) {
                carry = 1;
                digit -= 10;
            }
            else {
                carry = 0;
            }
            num.insert(num.begin(), 1, digit); 
            k /= 10;
        }
        
        if (carry >= 1) {
            num.insert(num.begin(), 1, 1);
        }
        
        return num;
    }
};

