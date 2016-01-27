/**
 * 1. 下一个最长子串可能开始的位置。
 * 2. 如果不使用map.find, 直接map[i]，如果i不存在会得到0，即新建立一个key-value。
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int len = s.size();
        unordered_map<char, int> cha_index;
        int start_index = 0; // 字符串开始的位置
        for (int i=0; i<len; ++i) {
            // 子串出现重复字符，下一次字符串开始在第一次出现的下一个位置
            if (cha_index.find(s[i]) != cha_index.end() && cha_index[s[i]] >= start_index) {
                start_index = cha_index[s[i]]+1;
            } 
            
            if (i-start_index+1 > max_len)
                max_len = i-start_index+1;
            
            cha_index[s[i]] = i;
            
            //cout << start_index << " " << max_len << endl;
        }
        return max_len;
    }
};