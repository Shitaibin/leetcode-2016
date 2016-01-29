/**
 * 不使用to_string快了很多。
 */
class Solution {
public:
    string countAndSay(int n) {
        string s = "1", next;
        int cnt, i;
        while (--n) {
            cnt = 1;
            next = "";
            for (i = 1; i < s.size(); ++i) {
                if (s[i] == s[i-1]) cnt++;
                else {
                    // next += cnt + '0' + s[i-1]; //bug: 因为next后面加的都是char型，多个char型相加等同于，int相加
                    next += cnt + '0';
                    next += s[i-1];
                    cnt = 1;
                }
            }
            next += cnt + '0';
            next += s[i-1];
            s = next;
        }
        return s;
    }
};