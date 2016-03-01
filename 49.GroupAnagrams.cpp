/*
 * 不足1个元素，没有相同的。
 * 同一类字符串，排序后结果相同。
 * 要求：组内字符串升序。
 */
 
class Solution {
private:
    struct Node{
        string str;
        string sorted_str;
        Node(string s): str(s), sorted_str(s) {
            sort(sorted_str.begin(), sorted_str.end());
        }
    };
    
    static bool comp(const Node& a, const Node& b) {
        if (a.sorted_str != b.sorted_str) {
            return a.sorted_str < b.sorted_str;
        }
        return a.str < b.str;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        
        if (strs.size() < 2) {
            result.push_back(strs);
            return result;
        }
            
            
        vector<Node> v;
        for (int i = 0; i < strs.size(); i++) {
            v.push_back(Node(strs[i]));
        }
        
        sort(v.begin(), v.end(), comp);
        
        vector<string> cur({v[0].str});
        for (int i = 1; i < v.size(); i++) {
            if (v[i].sorted_str == v[i-1].sorted_str) {
                cur.push_back(v[i].str);
            } else {
                result.push_back(cur);
                cur.clear();
                cur.push_back(v[i].str);
            }
        }
        result.push_back(cur);
        return result;
    }
};