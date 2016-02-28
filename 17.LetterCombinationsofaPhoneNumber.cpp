class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
            return result;
        
        vector<string> m;
        m.push_back(""); //0
        m.push_back("");
        m.push_back("abc");
        m.push_back("def");
        m.push_back("ghi");
        m.push_back("jkl");
        m.push_back("mno");
        m.push_back("pqrs");
        m.push_back("tuv");
        m.push_back("wxyz");
        
        result.push_back(""); //init
        for (char d : digits) {
            vector<string> new_result;
            for (auto letter : m[d-'0']) {
                for (int i = 0; i < result.size(); i++) {
                    new_result.push_back(result[i] + letter);
                }
            }
            result = new_result;
        }
        return result;
    }
};