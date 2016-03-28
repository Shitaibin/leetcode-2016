// //using long long type make sure there has no integer overflow
typedef long long utype;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if (denominator == 0) {
            return result;
        }
        if (numerator == 0) {
            return "0";
        }
        
        utype n = numerator;
        utype d = denominator;
        
        // deal with negative cases // forgot at the begining
        bool sign = ((float)n/d >= 0);
        if (n < 0) {n = -n;}
        if (d < 0) {d = -d;}
        if (sign == false) {
            result += "-";
        }
        
        utype remainder = n % d;
        utype division = n / d;
        
        ostringstream oss;
        oss << division;
        result += oss.str(); // integerpart
        
        if (remainder == 0) {
            // end like "2"
            return result;
        }
        
        result += ".";
        
        // 当余数再现时，就是找到的重复的开始位置
        unordered_map<utype, int> rec;
        for (int pos = result.size(); remainder != 0; pos++, remainder=(remainder*10)%d) {
            if (rec.find(remainder) != rec.end()) {
                result.insert(result.begin() + rec[remainder], '(');
                result.push_back(')');
                return result;
            }
            rec[remainder] = pos;
            result.push_back((remainder*10)/d + '0');
        }
        
        return result;
    }
};