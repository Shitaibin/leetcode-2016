
// v2: iterative, faster
class Solution {
private:
    vector<string> getDirs(string path) {
        stringstream ss(path);
        string dir;
        vector<string> result;
        while (getline(ss, dir, '/')) {
            if (dir.size()) {
                result.push_back(dir);
            }
        }
        return result;
    }
    
public:
    string simplifyPath(string path) {
        if (path.empty())
            return "";
        
        vector<string> dirs = getDirs(path);
        int ignor = 0;
        string result;
        for (int i=dirs.size()-1; i >= 0; i--) {
            string dir = dirs[i];
            if (dir == ".") {
                continue;
            }
            if (dir == "..") {
                ignor++;
            } else {
                if (ignor > 0) {
                    // ignore this dir
                    ignor--;
                } else {
                    // result.insert(result.begin(), "/"+dir); // Compile error, only can insert char
                    result = "/" + dir + result;
                }
            }
        }
        
        return result.empty() ? "/" : result;
    }
};

// v1: stack
class Solution {
private:
    vector<string> getDirs(string path) {
        stringstream ss(path);
        string dir;
        vector<string> result;
        while (getline(ss, dir, '/')) {
            if (dir.size()) {
                result.push_back(dir);
            }
        }
        return result;
    }
    
public:
    string simplifyPath(string path) {
        if (path.empty())
            return "";
        
        vector<string> stack;
        vector<string> dirs = getDirs(path);
        for (auto dir : dirs) {
            if (dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (stack.size())
                    stack.pop_back();
            } else {
                stack.push_back(dir);
            }
        }
        
        
        if (stack.empty())
            return "/";
        
        ostringstream oss;
        for (auto dir : stack) {
            oss << "/" << dir;
        }
        return oss.str();
    }
};