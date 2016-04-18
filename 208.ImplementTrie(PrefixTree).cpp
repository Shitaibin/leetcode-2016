
// 公司：Facebook

// 实现字典树的插入，查询。


// 时间复杂度分析
// v1: 使用STL map存放最多26个字母的映射关系。
// 所以插入与查找都最大为一个常数(26log26)，所以为O(1)。
// v2：使用数组代替map，插入与查找效率都为O(1)，
// 但v2中的系数，要小于v1中的系数，所以更快。
// 整体效率和树的高度有关，为O(h)，或者说是同
// 单词的长度有关。


// v2: 56ms, using array to replace map.
class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];  /* map from a to z */
    
public:
    // Initialize your data structure here.
    TrieNode() : isWord(false), children({0}) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        const int n = word.size();
        if (n <= 0) return ;
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new TrieNode();
            node = node->children[word[i] - 'a'];
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
            if (node->children[word[i] - 'a'] == NULL)
                return false;
            node = node->children[word[i] - 'a'];
        }
        return (isWord ? node->isWord : true);
    }
};



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