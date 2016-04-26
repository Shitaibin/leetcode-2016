// 公司：Airbnb

// 模拟题

// 1. 每行尽量放多的单词，两端对齐
// 2. 最后一行左对齐

// v1: 0ms
class Solution {
public:
    vector<string> fullJustify(vector<string>& word, int maxWidth) {
        vector<string> result;
        
        int i = 0;
        while (i < word.size()) {
            int line_len = 0;
            int j;
            // greedy
            for (j = i; j < word.size(); j++) {
                line_len += word[j].size();
                if (line_len + (j - i) > maxWidth) {
                    line_len -= word[j].size(); // [j] not included
                    break;
                }
            }
            
            // generate line
            string line = "";
            if (j != word.size()) {
                // not include [j]
                int blank = maxWidth - line_len;
                int count = j - i - 1; // the number of slots
                for (int k = i; k < (j - 1); k++) {
                    line += word[k];
                    
                    // add blanks
                    int slot_size = 0;
                    if (blank % count == 0) slot_size = blank/count;
                    else slot_size = blank/count + 1;   // left slot is bigger
                    line += string(slot_size, ' ');
                    // update blank infos
                    blank -= slot_size;
                    count--;
                }
                
                line += word[j-1]; // no space after the last word
            } else {
                // last line
                for (int k = i; k < (j - 1); k++) {
                    line += word[k];
                    line += " ";
                }
                line += word[j-1];
            }
            
            // got a line
            // may be need space, such as: only one word, "abcdefdfsd  "
            line += string((maxWidth - line.size()), ' ');
            result.push_back(line);
            
            // move i
            i = j;
        }
        return result;
    }
};