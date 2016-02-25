// 并没有限制字符只有小写字母，可以是任意字符
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        const int SIZE = 256;
        char maps[SIZE] = {0}, mapt[SIZE] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            if (maps[s[i]] == 0 && mapt[t[i]] == 0) {
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
            } else if (maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};