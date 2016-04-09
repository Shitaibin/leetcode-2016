// 0000 00 11 1111 1111 1111 1111 1111 1111
// (32bits,can be represented by an integer)
// the bit '1' from right to left, represent
// 'z' to 'a'.
// So, that's the thought of bitmap.

// very fast
class Solution {
    static const int bufsize = 2000;
    int word_bits[bufsize];
    int word_size[bufsize];
    const int INF = 0x03ffffff;
    
    int set_bits(string s) {
        int my_bits = 0;
        for (char c : s) {
            my_bits |= (1 << (c - 'a'));
            if (my_bits == INF) break; // 已经包含了所有字母
        }
        return my_bits;
    }
    
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            word_bits[i] = set_bits(words[i]);
            word_size[i] = words[i].size();
        }
        
        int max_prod = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                // bug, 逻辑与的运算符优先级比较低，需要加括号
                if ( (word_bits[i] & word_bits[j]) == 0 ) {
                    max_prod = max(max_prod, word_size[i] * word_size[j]);
                }
            }
        }
        return max_prod;
    }
};