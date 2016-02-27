class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = getWords(str);
        if (pattern.size() != words.size())
            return false;
        map<char, string> alpha_word;
        map<string, char> word_alpha;
        for (int i = 0; i < pattern.size(); i++) {
            if (alpha_word.find(pattern[i]) == alpha_word.end() && word_alpha.find(words[i]) == word_alpha.end()) {
                alpha_word[pattern[i]] = words[i];
                word_alpha[words[i]] = pattern[i];
            } else if (alpha_word[pattern[i]] == words[i] && word_alpha[words[i]] == pattern[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    vector<string> getWords(string str) {
        stringstream ss(str);
        vector<string> ret;
        string word;
        while (getline(ss, word, ' ')) {
            ret.push_back(word);
        }
        return ret;
    }
    
    template <typename T>
    void printVector(vector<T> v) {
        cout << "{ ";
        for (auto e : v) {
            cout << e << " ";
        }
        cout << "}" << endl;
    }
};