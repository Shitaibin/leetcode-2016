class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        for (int i = 1; i <= numRows; i++) {
            vector<int> cur;
            cur.push_back(1);
            int j;
            for (j = 1; j < i-1; j++) {
                cur.push_back(results[i-2][j-1] + results[i-2][j]);
            }
            if (j == i-1)
                cur.push_back(1);
            results.push_back(cur);
        }
        return results;
    }
};