// 公司：未知
// 
// 
// 本题的思想就是替换或利用树的性质（空节点的数量=叶节点的数量+1）。
// 
// v1: 4ms
// v2: -
// v3: 12 ms
// v4: 12 ms
// 
// 
// v4思路
// 本质上来讲，我们只是在统计，用不到stack，所以将v3中stack
// 换成统计，得到v4。
//
// 
// v3思路
// 空节点的数量=叶节点的数量+1
// 遇到非空节点进栈，空遇到空节点，从栈里弹出一个，
// 如果顺序是对的，最后栈为空，并且最后一个未'#'。
// 
// 
// v2思路
// 建立字符串栈，将preoder分割为字符串列表，然后将字符串依次入栈，
// 如果栈顶是"#"，栈顶的下一个是数字，则二者都弹出，然后压入
// 一个"#"，表示代替了子树。


// 
// v1思路
// 最基础的情况，叶节点：1,#,#
// 进阶情况1，左子树为叶节点: 2,1,#,#,#
// 进阶情况2，右子树为叶节点: 2,#,1,#,#
// 
// 如果我们把进阶情况中的`1,#,#`替换为`#`。
// 进阶情况1：2,#,#
// 进阶情况2: 2,#,#
// 同样化为了叶节点。
// 
// 因此得到这样一个思路：把所有的叶节点，全部换为空(#)。
// 这样迭代下去，直到找不到叶节点可替换，最后的结果必然是
// 一颗空树(#)。
// 
// 因为最后遍历的一个节点，一定叶节点，所以我们每次从后边
// 查找符合条件的叶节点。
// 
// 时间复杂度：每次都会消除一个叶节点，但每次都是从尾部开始遍历，
// 因此复杂度为O(N^2)。提交结果4ms，效率中等。
// 




// v1: O(N^2)，4ms。动手在纸上画出来的结果。
class Solution {
public:
    bool isValidSerialization(string preorder) {
        string& s = preorder;
        while (s.size() >= 5) {
            bool find_pattern = false;
            for (int i = s.size()-1; i>= 4; i--) {
                if (s[i] == '#' && s[i-2] == '#' && s[i-4] != '#') {
                    find_pattern = true;
                    int j = i-4-1;
                    while (j > 0 && s[j] != ',') j--; /* 寻找pattern开始的位置 */
                    s.replace(j+1, i-j, "#"); /* s[j+1, i] 替换为 # */
                    break;  /* start a trun search from the end */
                }
            }
            if (!find_pattern) break;
        }
        
        /* boundary: empty tree */
        return (s.size() == 1 && s[0] == '#');
    }
};


void test(string s, bool result) {
    Solution so;
    bool ret = so.isValidSerialization(s);
    if (ret != result) {
        cout << "test case fail: " << endl;
        cout << s << endl;
        cout << "true result: " << result<< endl;
        cout << "false ret: " << ret << endl;
    }
}

int main()
{
    test("#", true); // empty tree

    // true cases
    test("1,#,#", true);
    test("1,2,#,#,#", true);
    test("9,3,4,#,#,1,#,#,2,#,6,#,#", true);

    // false cases
    test("1,#", false);
    test("1,#,#,#,#", false);
    test("9,#,#,1", false);
    test("9,3,4,#,#,1,#,#,#,2,#,6,#,#", false);
    return 0;
}





// v4: without stack
class Solution {
    vector<string> split(const string& str) {
        vector<string> result;
        stringstream ss(str);
        string buf;
        while (getline(ss, buf, ',')) {
            result.push_back(buf);
        }
        return result;
    }
    
public:
    bool isValidSerialization(string preorder) {
        vector<string> strs = split(preorder);
        int count = 0;  /* the number of non-null nodes */
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "#") {
                if (count == 0) {
                    return i == (strs.size() - 1);
                }
                count--;
            }
            else {
                count++;
            }
        }
        return false;
    }
};


// v3: slow for using stringstream
class Solution {
    vector<string> split(const string& str) {
        vector<string> result;
        stringstream ss(str);
        string buf;
        while (getline(ss, buf, ',')) {
            result.push_back(buf);
        }
        return result;
    }
    
public:
    bool isValidSerialization(string preorder) {
        vector<string> strs = split(preorder);
        stack<string> sta;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "#") {
                if (sta.empty()) {
                    return i == (strs.size() - 1);
                }
                sta.pop();
            }
            else {
                sta.push(strs[i]);
            }
        }
        return false;
    }
};