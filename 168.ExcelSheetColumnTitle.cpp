class Solution {
public:
    string convertToTitle(int n) {
        vector<int> nums = transform(n, 26);
        return toTitle(nums);
    }
    
    vector<int> transform(int n, int base) {
        vector<int> res;
        while (n != 0) {
            n--;// start from zero
            res.push_back(n % base);
            n /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string toTitle(vector<int> v) {
        string title;
        for (auto e: v) {
            title += e + 'A';
        }
        return title;
    }
};