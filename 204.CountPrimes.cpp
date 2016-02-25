class Solution {
public:
    int countPrimes(int n) {
        vector<bool > isPrime(n, true);
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j+=i) {
                isPrime[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) cnt++;
        }
        return cnt;
    }
};