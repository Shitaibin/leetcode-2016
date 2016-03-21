// v1: backtracking, 有思路，但不够完全
// reference: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/palindromePartitioning/palindromePartitioning.cpp
class Solution {
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    
    void partitionHelper(string &s, int start, vector<string> &output, vector<vector<string> > &result) {
        if (start == s.size()) {
            result.push_back(output);
        }
        
        // find next palindrome string
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i) == true) {
                // put the current palindrome substring into ouput
                output.push_back(s.substr(start, i-start+1));
                // recursively check the rest substring
                partitionHelper(s, i+1, output, result);
                // take out the current palindrome substring, in order to check longer substring.
                output.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> output;
        partitionHelper(s, 0, output, result);
        return result;
    }
};