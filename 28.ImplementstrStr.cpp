/**
 * haystack为空, needle不空。
 * 
 * 特殊情况：
 * 1. needle空，空是任何串的子串，返回0；
 * 2. needle只含空白符，空白符也是字符，不单独处理。
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int nl = needle.size();
        int r = haystack.size()-nl;
        for (int i=0; i<=(r); i++) { //把r替换掉，运行时错误
            if (haystack[i] == needle[0] && haystack.substr(i, nl) == needle)
                return i;
        }
        return -1;
    }
};