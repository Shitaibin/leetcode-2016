class Solution {
    int count_one(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n-1);
            count++;
        }
        return count;
    }
    
public:
    vector<int> countBits(int num) {
        vector<int> result;
        for (int i = 0; i <= num; i++) {
        	result.push_back(count_one(i));
        }
        return result;
    }
};