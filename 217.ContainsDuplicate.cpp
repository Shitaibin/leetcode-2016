class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (auto e : nums) {
            if (s.find(e) == s.end()) {
                s.insert(e);
            } else {
                return true;
            }
        }
        return false;
    }
};