class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        
        for (i = s.size()-1; i >= 0 && s[i] == ' '; --i);
        int end = i;
        
        for ( ; i >= 0 && s[i] != ' '; --i);
        int start = i;
        cout << end << " " << start << endl;      
        return end - start;
    }
};