// v2: 快速
class Solution {
private:
    void restoreIpAddressesHelper(string &s, int start, int part_count, string ip, vector<string>& result) {
        int n = s.size();
        // too little or too much
        if (n-start < 4-part_count || n-start > (4-part_count)*3) {
            return;
        }
        
        // reach the end and get 4 parts
        if (start == n && part_count == 4) {
            // 3 ways remove the last dot
            // ip.erase(ip.end()-1, ip.end());
            ip.erase(ip.end()-1);
            // ip.pop_bacK(); // some complier may not support 
            result.push_back(ip);
            return;
        }
        
        // backtracking
        int num = 0;
        for (int i = start; i < start+3; i++) {
            num = num * 10 + s[i]-'0';
            if (num < 256) {
                ip += s[i];
                restoreIpAddressesHelper(s, i+1, part_count+1, ip+'.', result);
            }
            
            // 0.0.0.0 is valid but 0.01.011.0 is invalid
            if (num == 0) {
                break;
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        restoreIpAddressesHelper(s, 0, 0, ip, result);
        return result;
    }
};


// v1 : 得到每一段，然后判断是不是合理的IP
class Solution {
private:

string combineIP(vector<string> v) {
    ostringstream oss;
    oss << v[0] << "." << v[1] << "." << v[2] << "." << v[3];
    return oss.str();
}

int checkIP(string s) {
    if (s == "" || s.size() > 3) {
        return 0;
    }
    
    if (s.size() == 1) {
        return 1;
    }
    
    // "01" is also invalid
    if (s[0] == '0') {
        return 0;
    }
    
    stringstream ss(s);
    int x;
    ss >> x;
    return (x >= 0 && x <= 255);
}

void ipSolution(string s, int start, int left, vector<string> &solution, vector<string> &result) {
    if (left == 0 && start == s.size()) {
        // got a solution
        result.push_back(combineIP(solution));
    }
    
    if (left < 0) {
        return;
    }
    
    for (int i = start; i < start+3 && i < s.size(); i++) {
        string ip = s.substr(start, i+1-start);
        if (checkIP(ip)) {
            solution.push_back(ip);
            ipSolution(s, i+1, left-1, solution, result);
            solution.pop_back();
        } else {
            //break;
            // cout << ip << endl;
        }
    }
}

public:
    vector<string> restoreIpAddresses(string s) {
        // less than 4 digits
        vector<string> result;
        if (s.size() < 4) {
            return result;
        }
        
        // backtracking
        vector<string> solution;
        ipSolution(s, 0, 4, solution, result);
        return result;
    }
};