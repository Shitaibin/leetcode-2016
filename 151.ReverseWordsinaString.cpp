class Solution {
    vector<string> getWords(const string &s) {
        vector<string> words;
        string word;
        
        istringstream iss(s);
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
    
    
public:
    void reverseWords(string &s) {
        vector<string> words = getWords(s);
        s = "";
        
        for (int i = words.size()-1; i > 0; i--) {
            s += words[i] + " ";
        }
        if (words.size()) {
            s += words[0];
        }
    }
};