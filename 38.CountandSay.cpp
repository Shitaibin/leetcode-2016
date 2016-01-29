class Solution {
public:
    string countAndSay(int n) {
        string m = "1";
        while (--n) {
            m = getNext(m);
        }
        return m;
    }

private:
    string getNext(string s) {
        string ret = "";
        int cnt = 1, i;
        for (i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) cnt++;
            else {
                ret += to_string(cnt) + s[i-1];
                cnt = 1;
            }
        }
        ret += to_string(cnt) + s[i-1];
        return ret;
    }
};