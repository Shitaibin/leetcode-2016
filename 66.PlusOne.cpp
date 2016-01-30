class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, carry = 1;
        for (i = digits.size()-1; i>= 0; --i) {
            if (digits[i] == 9 && carry) {
                digits[i] = 0;
                //carry = 1;
            } else {
                digits[i] += 1;
                carry = 0;
                break;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};