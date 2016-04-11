// 
// 公司：FaceBook
// 
// 题目简要：h-index:至少h篇的引用大于h，剩下的N-h的引用值都小于等于h。
// 
// v1：O(NlogN)。根据公式计算。
// 
// v2：O(N)。根据h-index的计算公式，可以知道h-index可能的取值范围是[0,N]。
// 因此对[0,N]进行统计，对于大于N的完全可以记在N头上。然后从后向前，
// 统计总共的引用数量，满足h-index条件的h。得到v2.
// 
// v3：O(N)。一种升级思路，初始时h等于0，upgrade_count代表了大于等于h+1
// 的论文数量，upgra_count达到升级标准时，将h提升至h+1，更新
// upgrade_count。
// 


// v3: O(N)。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // upgrade_count是升级到h+1的统计，即大于等于h的统计
        int upgrade_count = 0, h = 0;
        int n = citations.size();
        int count[n+1];
        memset(count, 0, sizeof(count));
        
        for (int i = 0; i < n; i++) {
            int cur = citations[i];
            // 更新每个引用的统计，大于n时，记在n头上
            if (cur > n) count[n]++;
            else count[cur]++;
            
            if (cur >= h+1) {
                ++upgrade_count; // 更新统计
                if (upgrade_count >= h+1) { // 升级标准：至少与h+1个upgrade_count
                    // 升级
                    ++h;
                    // 更新数据
                    upgrade_count -= count[h];
                }
            }
        }
        return h;
    }
};


// v2: O(N)。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        vector<int> count(n+1, 0);
        // count
        for (int i = 0; i < n; ++i) {
            if (citations[i] > n) {
                ++count[n];
            }
            else {
                ++count[citations[i]];
            }
        }
        // check h
        int sum = 0;
        for (int h = n; h >= 0; h--) {
            sum += count[h];
            if (sum >= h) return h;
        }
        return 0;
    }
};



// v1: 朴素方案，这就是计算公式。O(NlogN)。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            h = max(h, min(i+1, citations[i]));
        }
        return h;
    }
};