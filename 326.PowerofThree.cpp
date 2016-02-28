// v1: loop, 124ms
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false; // DONT FORGET
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// v2: recursive, 168ms
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if (n == 0 || n%3 != 0) return false;
        return isPowerOfThree(n/3);
    }
};

// v3: 128ms, 32bits OS, 3^19 = 1162661467
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 ? (1162261467%n == 0) : false;
    }
};

// v4: 144ms, log opration
class Solution {
public:
    bool isPowerOfThree(int n) {
        double logRes = log10(n) / log10(3);
        return (logRes - int(logRes) == 0);
    }
};