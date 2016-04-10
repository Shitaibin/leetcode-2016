// 公司：未知

// v2: 由v1升级而来，时间从20ms降到4ms。
class Solution {
    int min(int a, int b, int c) {
        // call `min` in std, or compiler will think Solution has a `min(int, int)`
        return ::min( ::min(a,b), c );
    }
    
public:
    int nthUglyNumber(int n) {
        // 程序的测试是，多次调用nthUglyNumber而不会创建新的对象。
        // 使用static我们就可以使用上次v中的数据，不必重复计算。
        // 我们还需要计算到v[n-1]时的i,j,k信息，所以i,j,k也设置为static。
        static int i = 0, j = 0, k = 0;
        static vector<int> v(1, 1);
        
        if (v.size() >= n) return v[n-1];
        
        while (v.size() < n) {
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        
        return v.back();
    }
};


// v1: 
class Solution {
    int min(int a, int b, int c) {
        // call `min` in std, or compiler will think Solution has a `min(int, int)`
        return ::min( ::min(a,b), c );
    }
    
public:
    int nthUglyNumber(int n) {
        int i, j, k;
        i = j = k = 0;
        vector<int> v(1, 1);
        while (v.size() < n) {
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            // i,j,k对应相乘的结果可能都是next
            // 所以要挨个判断，而不是if-else
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        
        return v.back();
    }
};
