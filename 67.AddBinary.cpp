class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i, carry = 0;
        for (i = 0; i < a.size() && i < b.size(); i++) {
            int s = a[i]-'0'+b[i]-'0' + carry;
            add2ret(ret, s, carry);
        }
        // for a
        for (; i < a.size(); i++) {
            int s = a[i] - '0' + carry;
            add2ret(ret, s, carry);
        }
        // for b
        for (; i < b.size(); i++) {
            int s = b[i] - '0' + carry;
            add2ret(ret, s, carry);
        }
        // carry
        if (carry == 1) {
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void add2ret(string &ret, int s, int &carry) {
        //cout << carry << " " << (s & 1) << endl;
        carry = (s > 1);
        ret += '0' + (s & 1);
    }
};