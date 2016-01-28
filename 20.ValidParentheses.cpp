class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> char_map;
        char_map['('] = ')';
        char_map['['] = ']';
        char_map['{'] = '}';
        
        stack<char> pare_stack;
        int i;
        for (i=0; i<s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                pare_stack.push(s[i]);
            else {
                if (pare_stack.empty() || char_map[pare_stack.top()] != s[i]) {
                    return false;
                } else {
                    pare_stack.pop();
                }
            }
        }
        return pare_stack.empty();
    }
};