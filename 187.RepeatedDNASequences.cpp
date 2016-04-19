// 公司：LinkedIn


/**
 * v3: 20ms。以空间换时间。
 * 用位来表示4个字母，我们需要2位（00,01,10,11）。
 * 10个字母就拼出来一个20位的序列，
 * 如10个A为，000....000，共20个0，
 * 10个T为，111...111，共20个1，
 * 把这些值作为hash的val。所以共有2^20种可能的val。
 * 所以后面bitset的大小为(1<<20)，实际占用(1<<17)字节。
 * 
 * 为了加快计算10个字符的val，所以使用上个子串的后9个字符，
 * 和当前字符，拼接成新的val。
 * 
 * 对于每个子串而言，只有3中状态，没有出现，出现了1此，出现了多余1次。
 * 使用s1代表没有出现，或出现了1次，使用s2代表出现了1次以上。
 */


class Solution {
    int char2val(char c) {
        switch(c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        if (n <= 10) 
            return vector<string>();
            
        vector<string> result;
        bitset<(1<<20)> s1; /* 代表没有出现，或出现了1次 */
        bitset<(1<<20)> s2; /* 代表出现了1次以上 */
        
        int val = 0;
        /* 为第一个子串计算hash值 */
        for (int i = 0; i < 10; i++) 
            val = (val << 2) | char2val(s[i]);
        s1.set(val);
        
        int mask = (1 << 20) - 1;
        for (int i = 10; i < n; i++) {
            /* 计算以s[i]为结尾的子串的hash值 */
            // val = ((val << 2) & mask) | char2val(s[i]);
            /* better to understand */
            val = ((val << 2) | char2val(s[i])) & mask;
            if (s2[val])
                continue;
            if (s1[val]) {
                result.push_back(s.substr(i - 10 + 1, 10));
                s2.set(val);
            }
            else
                s1.set(val);
        }
        return result;
    }
};



// v2: 112ms，使用哈希函数加快。来自耗子。
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        unordered_map<size_t, int> count;
        hash<string> hash_func;  /* function object */
        vector<string> result;
        
        for (int i = 0; i <= (n-10); i++) {
            string sub_str = s.substr(i, 10);
            size_t hash_code = hash_func(sub_str);
            count[hash_code]++;
            if ( (count[hash_code]) == 2) {
                result.push_back(sub_str);
            };
        }
        
        return result;
    }
};


// v1: 140ms, O(N), using STL unordered_map
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        unordered_map<string, int> count;
        for (int i = 0; i <= (n-10); i++) {
            string sub_str = s.substr(i, 10);
            count[sub_str]++;
        }
        vector<string> result;
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second > 1) result.push_back(it->first);
        }
        return result;
    }
};