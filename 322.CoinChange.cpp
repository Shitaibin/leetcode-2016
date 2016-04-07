#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


template <typename T>
void print_vector(vector<T> v) {
    cout << "size = " << v.size() << ": ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


//dp[i] = min{dp[i-a[j]]}+1, for j in [1,n]
//dp[0] = 0
int coin_change(vector<int> a, int amount) {
    // dp: 使用 INT_MAX 作为没有找到分解方法的标记
    const int MAX = amount+1;
    vector<int> dp(amount+1, MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i >= a[j]) { // 每次都需要确保边界是安全的
                dp[i] = min(dp[i], dp[i-a[j]] + 1);
            }
        }
    }
    return dp[amount] != MAX ? dp[amount] : -1;
}


void test(vector<int> a, int amount, int result) {
    //print_vector(a);
    int ret = coin_change(a, amount);
    if (ret != result) {
        cout << "false result: " << ret << endl;
        cout << "test ";
        print_vector(a);
        cout << "test amount:" << amount << endl;
        assert(false);
    }
}



int main()
{
    test(vector<int>({}), 0, 0);
    test(vector<int>({2,5}), 0, 0);
    test(vector<int>({}), 1, -1);
    test(vector<int>({2}), 3, -1);
    test(vector<int>({2,5}), 6, 3);
    test(vector<int>({1}), 3, 3);
    test(vector<int>({2}), 4, 2);
    test(vector<int>({1,2,5}), 8, 3);
    test(vector<int>({1,2,5}), 10, 2);
    test(vector<int>({1,2,5}), 13, 4);
    test(vector<int>({474,83,404,3}), 264, 8);
    
    return 0;
}