string prefix(string sa, string sb) {
    int i;
    int la = sa.size(), lb = sb.size();
    for (i=0; i<la && i<lb && sa[i]==sb[i]; ++i);
    return sa.substr(0, i);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
            
        
        string longest = strs[0];
        for (int i=1; i<strs.size(); ++i) {
            longest = prefix(strs[i], longest);
        }
        return longest;
    }
};