// v2: faseter

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        // overall max product
        int max_prod = INT_MIN;
        // previous max positive product, >= 0
        int max_positive = 0;
        // previous min negative product, >= 0
        int min_negative = 0;
        for (int i = 0; i < nums.size(); i++) {
            int m = max_positive;
            int n = min_negative;
            if (nums[i] > 0) {
                max_positive = max(m * nums[i], nums[i]); // m may be zero, a new start
                min_negative = min(n * nums[i], 0); // n<=0, so no need using function min, but it will make it easier to understand
            } else if (nums[i] < 0) {
                max_positive = max(n * nums[i], 0); // n<=0, the same as the previous comment
                min_negative = min(m * nums[i], nums[i]); // m may be zero, a new start
            } else {
                max_positive = min_negative = 0; // current is zero, reset
            }
            max_prod = max(max_prod, max_positive);
        }
        return max_prod;
    }
};


// v1: 
class Solution {
    int max_3(int x, int y, int z) {
        if (x >= y && x >= z) {
            return x;
        }
        return (y >= z? y : z);
    }
    
    int min_3(int x, int y, int z) {
        if (x <= y && x <= z) {
            return x;
        }
        return (y <= z ? y : z);
    }
    
public:
    int maxProduct(vector<int>& nums) {
        // To remember the max/min product for previous position
        int maxPrev = nums[0], minPrev = nums[0];
        // To remember the max/min product for current position
        int maxHere = nums[0], minHere = nums[0];
        int maxProd = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            maxHere = max_3(maxPrev * nums[i], minPrev * nums[i], nums[i]);
            minHere = min_3(maxPrev * nums[i], minPrev * nums[i], nums[i]);
            maxProd = max(maxHere, maxProd);
            maxPrev = maxHere;
            minPrev = minHere;
        }
        
        return maxProd;
    }
};