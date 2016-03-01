class Solution {
private:
    string multiply(const string& num, char ch) {
        int n = ch-'0';
        string s;
        int carry = 0;
        for (int i = num.size()-1; i >= 0; i--) {
            int x = (num[i]-'0') * n + carry;
            s.insert(s.begin(), x%10+'0');
            carry = x/10;
        }
        if (carry > 0) {
            s.insert(s.begin(), carry+'0');
        }
        return s;
    }
    
    string strPlus(string n1, string n2) {
        string s;
        int carry = 0;
        int x;
        for (int i = n1.size()-1, j = n2.size()-1; i >= 0 || j >= 0; i--, j--) {
            int x1 = i>=0 ? n1[i]-'0' : 0;
            int x2 = j>=0 ? n2[j]-'0' : 0; // bug: 这里是j，不是i
            x = x1 + x2 + carry;
            carry = x/10;
            s.insert(s.begin(), x%10+'0'); //s += x%10+0;
        }
        if (carry > 0) {
            s.insert(s.begin(), carry+'0');
        }
        return s;
    }
    
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        
        int shift = 0;
        string result = "0";
        for (int i = num1.size()-1; i >= 0; i--) {
            string s = multiply(num2, num1[i]);
            for (int j = 0; j < shift; j++) {
                s.insert(s.end(), '0'); // s += "0";
            }
            result = strPlus(result, s);
            shift++;
        }
        
        if (result[0] == '0') { // bug: 判断号打为等号
            return "0";
        }
        return result;
    }
};