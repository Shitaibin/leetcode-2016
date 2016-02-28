// 记住当前左右括号的数量，只要左括号还有剩余就可以添加
// 左括号，只要右括号剩余的数量比多括号多，就可以添加
// 右括号
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generator(result, n, n, s);
        return result;
    }
    
    // left: 左括号的数量
    // right: 右括号的数量
    // s: 当前字符串
    void generator(vector<string> &result, int left, int right, string s) {
        // got a solution
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }
        // first, add left parenthese
        if (left > 0) {
            generator(result, left-1, right, s+"(");
        }
        // second, add right parenthese
        // 只要剩余的右括号多，我们就可以添加右括号
        //    if (right > 0 && right > left) {
        // 因为left最小为0，可以省写为
        if (right > left) {
            generator(result, left, right-1, s+")");
        }
    }
};


/*********************************
 *        错误的
 ********************************/
 
/**
 * 1生2
 * 2生3
 * 3不一定生4
 * 最初我的思路是：
 * 初始化，字符串为空，那么把空字符串结合一个括号，有3种方式：
 * 1. 放在字符串左边，
 * 2. 放在字符串右边，
 * 3. 把字符串括起来。
 * 因为得到的结果是一样的，所以1返回的是{"()"}。
 * n=2，3呢，同样进行3种操作，能得到正确的结果。
 * 并没有对n=4进行分析，测试时出现了2个bug：
 * bug1：vector并没有find方法。
 * bug2：3不一定生4。4种有一个是"(())(())""，是没有办法从3得来的。或者说
 * 一种新的生成方式是，把3劈开，得到4，但劈开可能有多种，出现了困难点。
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        if (n == 1) {
            result.push_back("()");
            return result;
        }
        
        vector<string> ret = generateParenthesis(n-1);
        for (int i = 0; i< ret.size(); i++) {
            string s = "()" + ret[i];
            insertResult(result, s);
            s  = ret[i] + "()";
            insertResult(result, s);
            s = "(" + ret[i] + ")";
            insertResult(result, s);
        }
        sort(result.begin(), result.end());
        return result;   
    }
    
    void insertResult(vector<string> &v, string s) {
        // if (find(v.begin(), v.end(), s)) {
        //     v.push_back(s);
        // }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == s)
                return ;
        }
        v.push_back(s);
    }
};