// 公司：LinkedIn


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