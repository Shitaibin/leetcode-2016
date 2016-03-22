// v3: AC.
// dp[i] = {(wordDict(s[:i])) || 
//         (dp[0] && wordDict(s[1:i])) || 
//         (dp[1] && wordDict(s[2:i])) ||
//         ...
//         (dp[i-1] && wordDict(s[3:i]))}
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        
        for (int i = 0; i < n; i++) {
            string w = s.substr(0, i+1);
            dp[i] = (wordDict.find(w) != wordDict.end());
            
            if (dp[i]) continue;
            
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    w = s.substr(j+1, i-j);
                    dp[i] = wordDict.find(w) != wordDict.end();
                    if (dp[i]) {
                        break;
                    }
                }
            }
            
        }
        
        return n == 0 ? false : dp[n-1];
    }
};



// v2: stay TLE, 减少创建string对象的次数，并不能带来多大的性能提升，
// 应当从算法上做出改进
class Solution {
    bool wordBreakHelper(string& s, int start, int& n, unordered_set<string>& wordDict) {
        if (start == n) {
            // breaked
            return true;
        }
        
        for (int i = start; i < n; i++) {
            string temp = s.substr(start, i+1-start);
            // cout << "t  :" << temp << endl;
            if (wordDict.find(temp) != wordDict.end()) {
                if ( wordBreakHelper(s, i+1, n, wordDict) ) {
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    // if the left part is a word, so we check the right part can be
    // break.
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        return wordBreakHelper(s, 0, n, wordDict);
    }
};


// v1: TLE, DFS
class Solution {
public:
    // if the left part is a word, so we check the right part can be
    // break.
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0) {
            return true;
        }
        
        for (int i = 0; i < n; i++) {
            string temp = s.substr(0, i+1);
            // cout << "t  :" << temp << endl;
            if (wordDict.find(temp) != wordDict.end()) {
                string str = s.substr(i+1);
                // cout << "str:" << str << endl;
                if ( wordBreak(str, wordDict) ) {
                    return true;
                }
            }
        }
        return false;
    }
};