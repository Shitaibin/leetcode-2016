// v2: 快速
class Solution {
void restoreIpAddressesHelper(string& s, int start, int partNum, string ip, vector<string>& result) {

    // too little or too much characters
    int len = s.size();
    if ( len - start < 4-partNum  || len - start > (4-partNum)*3 ) {
        return;
    }

    // reach the end and get 4 parts
    if (partNum == 4 && start == len){
        ip.erase(ip.end()-1, ip.end()); // remove the last dot
        result.push_back(ip);
        return;
    }

    // backtracking
    int num = 0;
    for (int i=start; i<start+3; i++){
        num = num*10 + s[i]-'0'; // get current num
        if (num<256){
            // invalid part
            ip+=s[i];
            restoreIpAddressesHelper(s, i+1, partNum+1, ip+'.', result);
        }         
        
        //0.0.0.0 valid, but 0.1.010.01 is not
        // 如果放到上一个if前面，所有以0为首，包括0自己，都不是合理的IP
        if (num == 0) {
            // case："0x"
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