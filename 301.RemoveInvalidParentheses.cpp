
// 公司:Facebook




// 对于每个字符，要么保留，要么删除。共两种状态，如果，字符串
// 长度为n，那么时间复杂度为指数级：2^n。
// 
// 剪枝：
// 1) 计算出不匹配的左括号和右括号数量，分别几位remove_left和
//     remove_right，在他们大于0的时候才递归删除剩余部分种的
//     括号。时间复杂度约为2^(remove_left + remove_right)。
//     如果需要删除的括号较少时，性能还是很好的。
// 2) 使用vector存放结果存在重复，因此需要使用set，不存在按序
//     访问，因此unordered_set可以进一步提升效率。

// v1：8ms, DFS
class Solution {
    void Helper(string& s, int idx, int pair,
                int remove_left, int remove_right,
                string solution, unordered_set<string>& result) {
        // idx: 字符的位置
        // pair: resolution中未匹配的左括号的数量

        // recursive ending
        if (idx >= s.size()) {
            if (pair == 0 && remove_left == 0 && remove_right == 0)
                result.insert(solution);
            return;
        }
        
        // meet other character
        if (s[idx] != '(' && s[idx] != ')') {
            Helper(s, idx+1, pair, remove_left, remove_right, solution+s[idx], result);
            return;
        }
        
        // meet '(', remove it or keep it
        if (s[idx] == '(') {
            // remove it
            if (remove_left > 0)
                Helper(s, idx+1, pair, remove_left-1, remove_right, solution, result);
            // keep it
            Helper(s, idx+1, pair+1, remove_left, remove_right, solution+s[idx], result);
        }
        
        // meet ')', remove it or keep it
        if (s[idx] == ')') {
            // remove it
            if (remove_right > 0)
                Helper(s, idx+1, pair, remove_left, remove_right-1, solution, result);
            // keep it, if there are some left alread
            if (pair > 0) 
                Helper(s, idx+1, pair-1, remove_left, remove_right, solution+s[idx], result);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // how many left and right parentheses need be removed
        int remove_left = 0, remove_right = 0;
        for (char c : s) {
            if (c == '(') {
                remove_left++;
            } else if (c == ')') {
                if (remove_left > 0) remove_left--;
                else remove_right++;
            }
        }
        
        unordered_set<string> result;
        Helper(s, 0, 0, remove_left, remove_right, "", result);
        return vector<string>( result.begin(), result.end() );
    }
};



v2: 168ms，最朴素的BFS
class Solution {
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')' && count-- == 0) {
                return false;
            }
        }
        return (count == 0);
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> existed;
        deque<string> queue;
        
        // init
        queue.push_back(s);
        existed.insert(s);
        
        bool found = false;
        while (!queue.empty()) {
            s = queue.front();
            queue.pop_front();
            
            if (isValid(s)) {
                result.push_back(s);
                found = true;
            }
            if (found) continue;
            
            // generate all next states
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '(' && s[i] != ')') continue;
                
                string str = s;
                str.erase(str.begin() + i);
                // not visited
                if (existed.find(str) == existed.end()) {
                    queue.push_back(str);
                    existed.insert(str);
                }
            }
        }
        
        return result;
    }
};