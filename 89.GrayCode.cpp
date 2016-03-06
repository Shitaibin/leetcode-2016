// http://baike.baidu.com/view/358724.htm
class Solution {
private:
    vector<int> grayCode_recursive(int n) {
        vector<int> ret;
        if (n == 0) {
            ret.push_back(0);
            return ret;
        }
        
        vector<int> r = grayCode_recursive(n-1);
        ret.insert(ret.end(), r.begin(), r.end()); // add positive order to ret
        
        // add reverse order to ret
        int addNum = 1<<(n-1);
        for (int i = r.size()-1; i >= 0; i--){
            ret.push_back(r[i] + addNum);
        }
        return ret;
    }
    
    vector<int> grayCode_iterative(int n) {
        vector<int> ret;
        int size = 1<<n;  // 2^n
        for (int i = 0; i < size; ++i) {
            ret.push_back((i >> 1) ^ i);
        }
        return ret;
    }
    
public:
    vector<int> grayCode(int n) {
        if (rand() % 2) {
            return grayCode_recursive(n);
        }
        return grayCode_iterative(n);
    }
};