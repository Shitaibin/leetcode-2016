/**
 * 按列更快，因为前缀可能很短。
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        char cur_ch;
        int cur_pos = 0;
        
        while (1) {
            if (cur_pos < strs[0].size()) {
                cur_ch = strs[0][cur_pos];
            } else {
                break;
            }
            
            bool find = false;
            for (int i=1; i<strs.size(); ++i) {
                if (cur_pos >= strs[i].size() || cur_ch != strs[i][cur_pos]) {
                    find = true;
                    break;
                }
            }
            
            if (find) break;
            else ++cur_pos;
        }
        return strs[0].substr(0, cur_pos);
    }
};