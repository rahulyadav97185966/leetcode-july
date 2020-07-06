//Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const size_t numDigits = digits.size();
        
        if (0 == numDigits) {
            return {1};
        }
        
        
        int idx = numDigits - 1;
        digits[idx] += 1;
        bool carry = digits[idx] > 9;
        while (carry) {
            digits[idx] = 0;
            --idx;
            if (idx < 0) {
                digits.insert(begin(digits), 1);
                carry = false;
            } else {
                digits[idx] += 1;
                if (digits[idx] < 10) {
                    carry = false;
                }
            }
        }
        
        return digits;
    }
};
