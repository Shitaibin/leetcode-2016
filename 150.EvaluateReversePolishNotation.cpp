class Solution {
    int str2int(const string &s) {
        int n;
        istringstream iss(s);
        iss >> n;
        return n;
    }
    
    int str2int_2(const string &s) {
        int n = 0;
        int i = 0;
        int flag = 1;
        if (s[i] == '-') {
            flag = -1;
            i++;
        } else if (s[i] == '+') {
            flag = 1;
            i++;
        }
        for (; i < s.size(); i++) {
            n = n * 10 + s[i]-'0';
        }
        return flag*n;
    }
    
    char getOperator(string s) {
        return s[0];
    }
    
    int pop(stack<int> &s) {
        int x = s.top();
        s.pop();
        return x;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto tok: tokens) {
            // if operator
            // get two numerb, and do it
            if (tok == "+") {
                int x1 = pop(s);
                int x2 = pop(s);
                s.push(x2+x1);
            } else if (tok == "-") {
                int x1 = pop(s);
                int x2 = pop(s);
                s.push(x2-x1);
            } else if (tok == "*") {
                int x1 = pop(s);
                int x2 = pop(s);
                s.push(x2*x1);
            } else if (tok == "/") {
                int x1 = pop(s);
                int x2 = pop(s);
                s.push(x2/x1);  
            } else {
                // else, string to int, and push it to stack
                s.push(str2int_2(tok));
            }
        }
        // stack.size() must be 1, or the expression is wrong
        return pop(s);
    }
};