class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return s;
        string t = "^";
        int i, n = s.length();
        for(i = 0; i < n; i++)
            t += "#" + s.substr(i, 1);
        t += "#$";
        n = t.length();
        int C = 0, R = 0;
        int P[n];
        memset(P, 0,sizeof(P));
        for(i = 1; i < n - 1; i++) {
            int i_mirror = C - (i - C);
            P[i] = R > C ? min(P[i_mirror], R - i) : 0;
            
            while(t[i + P[i] + 1] == t[i - P[i] - 1])
                P[i]++;
            if(i + P[i] > R) {
                R = i + P[i];
                C = i;
            }
        }
        int maxlen = 0, index = 0;
        for(i = 1; i < n - 1; i++) {
            if(P[i] > maxlen) {
                maxlen = P[i];
                index = i;
            }
        }
        return s.substr((index - 1 - maxlen) / 2, maxlen);
    }
};
