
// v2: dynamic
// 建立一个三角形v，存放当前节点的最小路径和
class Solution {
private:
    inline int min(int x, int y, int z) {
        int n = x<y? x:y;
        return (n<z?n:z);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector< vector<int> > v;
        for (int i = 0; i < triangle.size(); i++) {
            if (i == 0) {
                v.push_back(triangle[0]);
                continue;
            }
            
            vector<int> tmp;
            for (int j = 0; j < triangle[i].size(); j++) { // miss i
                int x, y, z;
                x = y = z = INT_MAX;
                if (j-1 >= 0) {
                    x = v[i-1][j-1];
                }
                if (j < v[i-1].size()) {
                    y = v[i-1][j];
                }
                tmp.push_back( min(x,y,z) + triangle[i][j] );
            }
            v.push_back(tmp);
        }
        
        int result = INT_MAX;
        if (v.size() > 0) {
            vector<int> &t = v[v.size()-1];
            for (int i = 0; i < t.size(); i++) {
                if (t[i] < result) {
                    result = t[i];
                }
            }
        }
        
        
        return result;
    }
};

// v1, backtracking ,TLE
class Solution {
    void minimumTotalHelper(vector<vector<int>>& triangle, int i, int j, int cur_sum, int &result) {
        if (i >= triangle.size()) {
            if (result > cur_sum) {
                result = cur_sum;
            }
            return; // forget this
        }
        
        cur_sum += triangle[i][j];
        for (int k = j; k <= j+1 && k < triangle[i].size(); k++) {
            minimumTotalHelper(triangle, i+1, k, cur_sum, result);
        }
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = INT_MAX;
        minimumTotalHelper(triangle, 0, 0, 0, result);
        return result;
    }
};