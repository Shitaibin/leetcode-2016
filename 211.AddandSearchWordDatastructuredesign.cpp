
// 公司：Facebook

// 相关题目：Google，208. Implement Trie (Prefix Tree)



// v2: 76ms,使用数组构建trie。
class DictNode {
public:
    bool isWord;
    DictNode* children[26];
    
    DictNode() : isWord(false), children({0}) {}
};

class WordDictionary {
public:
    DictNode* trie;

    WordDictionary() {
        trie = new DictNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        DictNode* node = trie;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (node->children[idx] == NULL) 
                node->children[idx] = new DictNode();
            node = node->children[idx];
        }
        node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return reg_search(word, 0, trie);
    }
    
    // Cut from 156ms to 80ms, by using reference.
    // If check node->children[i] is valid, can reduce
    // a recursion level. It can cut from 80ms to 76ms.
    // But in this way, it will be more clear.
    bool reg_search(string& word, int idx, DictNode* node) {
        // recursive ending
        if (node == NULL) return false;
        if (idx >= word.size()) {
            return node->isWord;
        }
        
        if (word[idx] == '.') {
            // all match '.', search next level
            for (int i = 0; i < 26; i++) {
                if (reg_search(word, idx + 1, node->children[i]))
                        return true;
            }
            // no children match the left sub string
            return false;
        }
        // try to match `word[idx] - 'a'`.
        return reg_search(word, idx + 1, node->children[word[idx] - 'a']);
    }
};




// v1: 216ms，slow. using map build tree
class DictNode {
public:
    bool isWord;
    unordered_map<char, DictNode*> children;
};

class WordDictionary {
    
    
public:
    DictNode* root;
    
    WordDictionary() {
        root = new DictNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        DictNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->children.find(word[i]) == node->children.end())
                node->children.insert(make_pair(word[i], new DictNode()));
            node = node->children[word[i]];
        }
        node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.empty()) return false;
        return reg_search(word, 0, root);
    }
    
    bool reg_search(string& word, int idx, DictNode* node) {
        // all is match, the last thing is whether current node
        // is a word or not
        if (idx >= word.size()) return node->isWord;
        
        if (word[idx] == '.') {
            // all children match it, find it in next level
            for(auto it = node->children.begin(); it != node->children.end(); it++) {
                if (reg_search(word, idx+1, it->second))
                    return true;
            }
            return false;
        }
        
        // no children match it
        if (node->children.find(word[idx]) == node->children.end())
            return false;
        // match, find in next level
        return reg_search(word, idx+1, node->children[word[idx]]);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");




