// v1: BFS, reference
// reference: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/wordLadder/wordLadder.cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        // Using a map for twp purpose
        // 1) store the distance so far.
        // 2) remove the duplications.
        
        // map
        unordered_map<string, int> dist; // distance
        dist[beginWord] = 1;
        
        // queue
        queue<string> q;
        q.push(beginWord);
        
        // queue not empty
        while (q.size()) {
            string word = q.front();
            q.pop();
            
            // if endWord, break
            if (word == endWord) {
                break;
            }
            
            // else find next word, add to queue
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (wordList.find(temp) != wordList.end() &&
                        dist.find(temp) == dist.end()) {
                            // temp in wordlist but not in dist
                            dist[temp] = dist[word] + 1;
                            q.push(temp);
                    }
                }
            }
        }
        
        // return result
        return (dist.find(endWord) == dist.end() ? 0 : dist[endWord]);
        // return dist[endWord];   // short, but slower
    }
};