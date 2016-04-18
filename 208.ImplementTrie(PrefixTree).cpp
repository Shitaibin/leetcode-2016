

// v1: 132ms, Using STL map
class TrieNode {
public:
    // If private, compile error.
    // May be testing visits them
    bool isWord;
    map<char, TrieNode*> children; /* unordered map make it slow, why? */
    
public:
    // Initialize your data structure here.
    TrieNode() : isWord(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        const int n = word.size();
        if (n <= 0) return;
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->children.find(word[i]) == node->children.end())
                node->children.insert( make_pair(word[i], new TrieNode()) );
            node = node->children[word[i]];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return retrieve(word, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return retrieve(prefix, false);
    }

private:
    TrieNode* root;
    
    bool retrieve(const string& word, bool isWord) {
        const int n = word.size();
        if (n <= 0) return false;
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->children.find(word[i]) == node->children.end())
                return false;
            node = node->children[word[i]];
        }
        return (isWord ? node->isWord : true);
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");