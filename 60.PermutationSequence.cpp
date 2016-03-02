/*
 * 生成n!个字符串，然后排序，时间复杂度n!log(n!)。
 * 太高，所以不能生成全部的。
 * 后来想了一个办法，但思路并不完全清晰，已经接近v2的办法。
 */

 // v1: TLE
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1)
            return "1";
        
        string nums;
        for (int i=1; i<=n; i++) {
            nums.insert(nums.end(), i+'0');
        }
        vector<string> result;
        result.push_back(nums);
        // if(nums.size() < 2) {
        //     return result[0];
        // }
        
        
        for (int pos=0; pos<nums.size()-1; pos++) {
            int result_size = result.size();
            for (int i=0; i<result_size; i++) {
                string s = result[i];
                // tack each number to the first place
                for (int j=pos+1; j<s.size(); j++) {
                    swap(s[j],s[pos]);
                    result.push_back(s);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result[k-1];
    }
};

// v2: iterative
// https://github.com/haoel/leetcode/blob/master/algorithms/cpp/permutationSequence/permutationSequence.cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int total = 1;  // n!
        for (int i=1; i<=n; i++) {
            num.push_back(i);
            total *= i;
        }
        
        // invalid k
        if (k > total) {
            return "";
        }
        
        // Construct the k-th permutation with a list of n numbers
        // Idea: group all permutations according to their first number (so n groups, each of
        // (n-1)! numbers), find the group where the k-th permutation belongs, remove the common
        // first number from the list and append it to the resulting string, and iteratively
        // construct the (((k-1)%(n-1)!)+1)-th permutation with the remaining n-1 numbers
        int group = total;
        stringstream ss;
        while (n>0) {
            group = group / n; // size of next group
            int idx = (k-1) / group; // think about case: k==group and k==group+1
            ss << num[idx];
            num.erase(num.begin()+idx);
            n--;
            k -= group*idx;
        }
        
        return ss.str();
    }
};