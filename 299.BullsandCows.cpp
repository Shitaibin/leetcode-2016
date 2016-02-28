class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size()) {
            return "";
        }
        int cnt = 0;
        int ms[10] = {0};
        int mg[10] = {0};
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                cnt++;
            } else {
                ms[secret[i]-'0']++;
                mg[guess[i]-'0']++;
            }
        }
        
        int cows = 0;
        for (int i = 0; i < 10; i++) {
            cows += min(ms[i], mg[i]);
        }
        
        ostringstream oss;
        oss << cnt << "A" << cows << "B";
        return oss.str();
    }
};