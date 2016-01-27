/**
 * 遍历每个元素，找出以此为中心的最长子串，并判断是否是全局最长子串。
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len=1, max_start=0;
        for (int i=0; i<s.size(); ++i) {
            // first: i center
            int j;
            for (j=1; i-j>=0 && i+j<s.size(); ++j) {
                if (s[i-j] != s[i+j]) {
                    //cout << s[i-j] << s[i+j] << endl;
                    //max_len = max(2*j+1, max_len);
                    if (2*j-1 > max_len) {
                        max_len = 2*j-1;
                        max_start = i-j+1;
                    }
                    break;
                }
            }
            if (2*j-1 > max_len) {
                max_len = 2*j-1;
                max_start = i-j+1;
            }
                    
            // second: no center
            int k;
            for (j=i, k=i+1; j>=0 && k<s.size(); --j, ++k) {
                if (s[j] != s[k]) {
                    //max_len = max(k-j+1, max_len);
                    if (k-j-1 > max_len) {
                        max_len = k-j-1;
                        max_start = j+1;
                    }
                    break;
                }
            }
            if (k-j-1 > max_len) {
                max_len = k-j-1;
                max_start = j+1;
            }
        }
        
        return s.substr(max_start, max_len);
    }
};