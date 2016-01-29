/**
 * 特殊情况：
 * 1. needle空，空是任何串的子串，返回0；
 * 2. needle只含空白符，空白符也是字符，不单独处理。
 * 3. needle长度小。
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int nl = needle.size();
        int r = haystack.size()-nl;
        // 把r替换掉，运行时错误：size()返回的为unsinged，当needle短时，
        // 小unsigned减大unsigned得到是更大的正数
        for (int i=0; i<=r; i++) { 
            if (haystack[i] == needle[0] && haystack.substr(i, nl) == needle)
                return i;
        }
        return -1;
    }
};


/**
 * 不使用string函数。
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int nl = needle.size();
        int hl = haystack.size();
        for (int i=0, j; i<=hl-nl; i++) { 
            for (j=0; j<nl && haystack[i+j] == needle[j]; ++j);
            if (j == nl) return i;
        }
        return -1;
    }
};