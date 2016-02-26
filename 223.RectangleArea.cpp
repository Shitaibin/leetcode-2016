
// 在做减法时，存在越界，因此改为long long
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap = max((long long)min(C,G) - max(A,E), (long long)0) * max((long long)min(D,H) - max(B,F), (long long)0);
        return (C-A)*(D-B) - overlap + (G-E)*(H-F);
    }
};