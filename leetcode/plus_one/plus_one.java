class Solution {
    public int[] plusOne(int[] digits) {
        int lastIndex = digits.length - 1;
        if (digits[lastIndex] != 9) {
            digits[lastIndex] += 1;
            return digits;
        }
        
        int carryIn = 1;
        for (; lastIndex > 0; lastIndex--) {
            digits[lastIndex] += carryIn;
            if (digits[lastIndex] == 10) {
                digits[lastIndex] = 0;
                carryIn = 1;
            } else {
                carryIn = 0;
            }
        }
        digits[lastIndex] += carryIn;
        if (digits[lastIndex] == 10) {
            digits[lastIndex] = 0;
            int[] newDigits = new int[digits.length + 1];
            newDigits[0] = 1;
            for (int i = 1; i < newDigits.length; i++) {
                newDigits[i] = digits[i - 1];
            }
            return newDigits;
        }
        
        return digits;
    }
}
