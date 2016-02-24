class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int base = 26;
        for (auto e : s) {
            res = res * base + e - 'A' + 1;
        }
        return res;
    }
};