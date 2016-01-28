class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> char_map;
        char_map['('] = ')';
        char_map['['] = ']';
        char_map['{'] = '}';
        
        stack<char> pare_stack;
        for (char c:s) {
            if (c == '(' || c == '[' || c == '{')
                pare_stack.push(c);
            else {
                if (pare_stack.empty() || char_map[pare_stack.top()] != c)
                    return false;
                else
                    pare_stack.pop();
            }
        }
        return pare_stack.empty();
    }
};