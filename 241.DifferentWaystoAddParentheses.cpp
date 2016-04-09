// 公司：未知

// 算法重要性，远比使用几个引用重要的多。

// v2: 快。增加了cache。
// v3：更模块化。
// 思路：根据每个操作符分成两半，然后分别计算两半的值，
// 将计算得来的结果，插入到最终结果中。


class Solution {
    // cache是作为整个解决方案的一部分，可以作为成员
    map<string, vector<int>> cache; 
    
    vector<int> calc(vector<int>& a_ret, vector<int>& b_ret, const char& op){
        vector<int> result;
        int temp_ret = 0;
        for (int i = 0; i < a_ret.size(); i++) {
            int& a = a_ret[i];
            for (int j = 0; j < b_ret.size(); j++) {
                int& b = b_ret[j];
                switch(op) {
                    case '+': temp_ret = a+b; break;
                    case '-': temp_ret = a-b; break;
                    case '*': temp_ret = a*b; break;
                }
                result.push_back(temp_ret);
            }
        }
        return result;
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        if (cache.find(input) != cache.end()) {
            return cache[input];
        }
        
        vector<int> result;
        if (input.empty()) {
            // input is empty, it means there is a negative number
            result.push_back(0);
        }
        else {
            for (int i = 0; i < input.size(); i++) {
                if (isdigit(input[i])) {
                    continue;
                }
                else { 
                    char op = input[i];
                    vector<int> a_ret = diffWaysToCompute(input.substr(0, i));
                    vector<int> b_ret = diffWaysToCompute(input.substr(i+1));
                    vector<int> ret = calc(a_ret, b_ret, op);
                    result.insert(result.end(), ret.begin(), ret.end());
                }
            }
            if (result.empty()) {
                // no operator, input is a number
                result.push_back(atoi(input.c_str()));
            }
        }
        
        // 错误：forget update, it doesn't work
        cache.insert(make_pair(input, result));
        
        return result;
    }
};