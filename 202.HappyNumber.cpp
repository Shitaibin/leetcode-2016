class Solution {
public:
    bool isHappy(int n) {
        set<int> nums;
        while (n != 1 && nums.find(n) == nums.end()) {
            nums.insert(n);
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};