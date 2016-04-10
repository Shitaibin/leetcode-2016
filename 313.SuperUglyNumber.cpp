// 由264：ugly number(2)转变而来
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        const int m = primes.size();
        vector<int> v(n);
        vector<int> indexs(m, 0);
        vector<int> nexts(m);
        v[0] = 1;
        
        for (int i = 1; i < n; i++) {
            int min_next = INT_MAX;
            for (int j = 0; j < m; j++) {
                nexts[j] = v[indexs[j]] * primes[j];
                min_next = min(min_next, nexts[j]);
            }
            for (int j = 0; j < m; j++) {
                if (min_next == nexts[j]) {
                    indexs[j]++;
                }
            }
            v[i] = min_next;
        }
        return v[n-1];
    }
};