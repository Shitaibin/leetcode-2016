class Solution {
public:
    int trailingZeroes(int n) {
        int z = 0;
        while (n) {
            z += n /= 5;
        }
        return z;
    }
};