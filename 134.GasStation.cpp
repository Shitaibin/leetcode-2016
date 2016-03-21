// 暴力TLE. 看似简单，实则不简单。

// v1: 贪心
// 这是一个向两边扩展的策略。如果能从当前加油站移动到下一个加油站，
// 就一直移动，否则，将开始加油站向前移动一个位置，直到有汽油
// 能移动到下一个加油站。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;
        int start = gas.size(); // start from the end to beginning
        int total = 0;
        
        do {
            if (total + gas[current] - cost[current] >= 0) {
                total += (gas[current] - cost[current]);
                current ++; // can go from current to current+1
            } else {
                start--; // not enough gas, try to start the one before origin start point
                total += (gas[start] - cost[start]);
            }
        } while (current != start);
        
        return total >= 0 ? start % gas.size() : -1;
    }
};