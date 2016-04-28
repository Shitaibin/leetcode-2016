// 公司：Google


// 重叠分两种：
// 1. 部分重叠。
// 2. 包含。


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


// v1: O(NlogN)。588ms。排序，然后合并。
class Solution {
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> result;
        for (int i = 0; i < intervals.size(); i++) {
            if (result.empty()) {
                result.push_back(intervals[i]);
                continue;
            }
            Interval& in = result.back();
            if (intervals[i].start <= in.end) {
                // overlaped
                if (intervals[i].end > in.end)
                    in.end = intervals[i].end;
            } else {
                // no overlap
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};