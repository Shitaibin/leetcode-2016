class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ms(26,0), mt(26,0); // faster than map
        for (auto e : s) {
            ms[e-'a']++;
        }
        for (auto e : t) {
            mt[e-'a']++;
        }
        return ms == mt;
    }
};