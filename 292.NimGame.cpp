// 判断你能否赢，不是判断一定赢
// https://github.com/haoel/leetcode/blob/master/algorithms/cpp/nimGame/nimGame.cpp

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};