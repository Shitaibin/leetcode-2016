// v2 is faster

// v2: https://en.wikipedia.org/wiki/Newton%27s_method
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double last = 0;
        double result = 1;
        while (result != last) {
            last = result;
            result = (result + x/result) / 2;
        }
        return result;
    }
};

// v1: binary search
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        
        //the sqrt is not greater than x/2+1
        int r = x/2+1;
        int l = 0;
        
        // binary search
        while (l <= r) {
            int mid = l + (r-l)/2;
            long long sq = (long long)mid * (long long)mid;
            if (sq == x)
                return mid;
            if (sq < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
