//Count[i] = Count[i-1]              if S[i-1] is a valid char (not '0')
//         = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char (10 to 26).
class Solution {
private:
    int check(char ch) {
        // check 0 or not
        return (isdigit(ch) && ch != '0');
    }
    
    int check(char ch1, char ch2) {
        // check it's' between 10 andd 26
        return (ch1=='1' || (ch1=='2' && ch2<='6'));
    }
    
public:
    int numDecodings(string s) {
        if (s.size() <= 0) return 0;
        if (s.size() == 1) return check(s[0]);
        
        vector<int> dp(s.size(), 0);
        
        dp[0] = check(s[0]);
        dp[1] = check(s[0]) * check(s[1]) + check(s[0], s[1]);  // special
        for (int i = 2; i < s.size(); i++) {
            if (!isdigit(s[i])) break;
            if (check(s[i])) {
                dp[i] = dp[i-1];
            }
            if (check(s[i-1], s[i])) {
                dp[i] += dp[i-2];
            }
        }
        int result = dp[s.size()-1];
        return result;
    }
};