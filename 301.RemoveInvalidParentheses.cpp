
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



// v2: 168ms，最朴素的BFS，时间复杂度指数级。
// 对于s，分别移除每一个字符，看得到的新字符是否是有效的组合，
// 如果是，那么证明了，本层就是移除最少的结果。
// 否则，根据新字符，再删除一个字符。对于每一层的结果，
// 都放到队列里面，每次从队列中取一个元素去检验。
// 那些新生成的字符串，就是下一层的状态。

// 这个算法之所以慢，是因为，删除每一个元素去，生成下一个状态，太费时间了。
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



// v3: 4ms.
// https://leetcode.com/discuss/68909/share-my-c-bfs-solution-4ms
class Solution {
public:
vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    if (s.size() == 0) {
        ans.push_back("");
        return ans;
    }

    deque<string> queue;
    unordered_set<string> exists;
    queue.push_back(s);
    while (!queue.empty()) {
        string target_str = queue.front();
        queue.pop_front();
        // cut from 172ms to 92ms
        if (exists.find(target_str) != exists.end()) {
            continue;
        }
        // cut from 16 to 4ms
        exists.insert(target_str);
        int invalid_point = findInvalidPoint(target_str);
        if (invalid_point == -1) {
            ans.push_back(target_str);
            continue;
        }
        int start = 0;
        int limit = target_str.size();
        if (target_str[invalid_point] == LC) {
            start = invalid_point;
        } else {
            limit = invalid_point + 1;
        }
        for (int i = start; i < limit; ++i) {
            // only need to remove which the same as [invalid_point]
            if (target_str[i] != target_str[invalid_point]) {
                continue;
            }
            // skip duplicates
            // cut from 92ms to 16ms, no need to search 
            if (i != start && target_str[i-1] == target_str[i]) {
                continue;
            }
            // generate next state
            string tmp_s = target_str.substr(0, i);
            if (i != target_str.size() - 1) {
                tmp_s.append(target_str.substr(i+1, target_str.size()));
            }
            queue.push_back(tmp_s);
        }
    }

    return ans;
}
private:
    const char LC = '(';
    const char RC = ')';
    int findInvalidPoint(string& s) {
        stack<pair<char, int> > st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == LC) {
                st.push(pair<char, int>(s[i], i));
            } else if (s[i] == RC) {
                // too much right parenthese
                if (st.size() == 0) {
                    return i;
                } 
                st.pop();
            }
        }
        // too much left parenthese or 
        // it is valid
        int top = -1;
        if (!st.empty()) {
            top = st.top().second;
            st.pop();
        }
        return top;
    }
};