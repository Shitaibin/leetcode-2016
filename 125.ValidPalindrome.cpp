// v1
class Solution {
public:
    bool isPalindrome(string s) {
        string new_s;
        for (auto e : s) {
            if (e >= 'a' && e <= 'z') {
                new_s += e;
            } else if (e >= 'A' && e <= 'Z') {
                new_s += e - 'A' + 'a';
            } else if (e >= '0' && e <= '9') {
                new_s += e;
            }
        }
        for (int i = 0, j = new_s.size()-1; i <= j; i++, j--) {
            if (new_s[i] != new_s[j])
                return false;
        }
        return true;
    }
};

// v2
class Solution {
public:
    bool isPalindrome(string s) {
        string new_s;
        for (auto e : s) {
            if (isalpha(e) || isdigit(e)) {
                new_s += tolower(e);
            }
        }
        for (int i = 0, j = new_s.size()-1; i <= j; i++, j--) {
            if (new_s[i] != new_s[j])
                return false;
        }
        return true;
    }
};
