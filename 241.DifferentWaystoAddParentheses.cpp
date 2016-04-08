// 公司：未知

// v2: 快。增加了cache。
// 思路：根据每个操作符分成两半，然后分别计算两半的值，
// 将计算得来的结果，插入到最终结果中。


class Solution {
    vector<int> calc(vector<int>& a_ret, vector<int>& b_ret, const char& op) {
        // caculate
        vector<int> result;
        for (int i = 0; i < a_ret.size(); i++) {
            int a = a_ret[i];
            for (int j = 0; j < b_ret.size(); j++) {
                int b = b_ret[j];
                if (op == '+') {
                    result.push_back(a+b);
                }
                else if (op == '-') {
                    result.push_back(a-b);
                }
                else if (op == '*') {
                    result.push_back(a*b);
                }
                else {
                    cout << "something wrong: " << op << endl;
                    assert(false);
                }
            }
        }
        return result;
    }
    
    vector<int> split_get_value(const string& s) {
        // accelerate
        static map<string, vector<int>> cache;
        if (cache.find(s) != cache.end()) {
            return cache[s];
        }
        
        vector<int> result;
        if (s.empty()) {
            // s is empty, it means there is a negative number
            result.push_back(0);
        }
        else {
            int i;
            for (i = 0; i < s.size(); i++) {
                if (isdigit(s[i])) {
                    continue;
                } else {
                    vector<int> a_ret = split_get_value(s.substr(0, i));
                    vector<int> b_ret = split_get_value(s.substr(i+1));
                    vector<int> ret = calc(a_ret, b_ret, s[i]);
                    result.insert(result.end(), ret.begin(), ret.end());
                }
            }
            if (result.empty()) {
                // no operator, s is a number
                result.push_back(atoi(s.c_str())); // 使用atoi，参数使用字符数组
            }
        }
        
        // update cache
        cache.insert(make_pair(s, result));
        
        return result;
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        return split_get_value(input);
    }
};