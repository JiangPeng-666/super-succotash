#include <bits/stdc++.h>

using namespace std;
/*
* 对于LC 70.爬楼梯使用完全背包进行求解过程中的顺序问题的探究
* 并且和LC 518.零钱兑换进行比较
* LC 70中要求的是排列数，即(1，2)和(2，1)不算同一种
* LC 518中要求的是组合数
* 结论：要求排列数只能在一维中先体积后物品才可以完成
* 要求组合数就是在一维中先物品后体积或者二维情况
* 
*/


class Solution {
public:
    int climbStairs(int n) {
        // 可以跨的台阶步数，存储为数组，便于后续遍历
        int nums[3] = {0, 1, 2};
        
        // // ======================一维情况=====================
        // vector<int> dp(n + 1);
        // dp[0] = 1;

        // // 一维，先物品后体积，两重循环, 求出的是组合数
        // for (int i = 1; i <= 2; ++i)
        //     for (int j = nums[i - 1]; j <= n; ++j)
        //         dp[j] += dp[j - nums[i - 1]];

        // // 一维，先体积后物品，两重循环，求出的是排列数
        // for (int j = 0; j <= n; ++j)
        //     for (int i = 1; i <= 2; ++i)
        //         if (j >= nums[i])
        //             dp[j] += dp[j - nums[i]];

        // return dp[n];

        // ======================二维情况=====================
        // dp[i][j]表示只使用前i个步数，可以到达j的方法数量
        vector<vector<int>> dp(3, vector<int>(n + 1));

        // 初始化
        dp[0][0] = 1;
        // // 如果这里进行了列初始化，那下面的j就可以从1开始
        // for (int i = 0; i <= 2; i++) 
        //     dp[i][0] = 1;
        
        // 如果这里没有进行列初始化，那下面的j必须从0开始
        // dp[0][0] = 1;

        // // 二维，先体积后物品，两重循环, 求出的是组合数
        // for (int j = 0; j <= n; ++j)
        //     for (int i = 1; i <= 2; ++i) {
        //         dp[i][j] = dp[i - 1][j];
        //         if (j >= nums[i])
        //             dp[i][j] += dp[i][j - nums[i]];
        //     }   

        // // 二维，先体积后物品，三重循环, 求出的是组合数
        // for (int j = 1; j <= n; ++j)
        //     for (int i = 1; i <= 2; ++i) {
        //         for (int k = 0; k * nums[i] <= j; ++k)
        //             dp[i][j] += dp[i - 1][j - k * nums[i]];
        //     }   

        
        // // 二维，先物品后体积，两重循环，求出的是组合数
        // for (int i = 1; i <= 2; ++i)
        //     for (int j = 0; j <= n; ++j) {
        //         dp[i][j] = dp[i - 1][j];
        //         if (j >= nums[i])
        //             dp[i][j] += dp[i][j - nums[i]];
        //     }   

        // 二维，先物品后体积，三重循环, 求出的是组合数
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= n; ++j) {
                for (int k = 0; k * nums[i] <= j; ++k)
                    dp[i][j] += dp[i - 1][j - k * nums[i]];

            

        return dp[2][n];
    }
    }
};

int main() {
    Solution solution;

    // 可以改变输入的n，正确答案可在这里获得 https://leetcode.cn/problems/climbing-stairs/
    // 3: 3, 5: 8
    cout << solution.climbStairs(5) << endl;

    return 0;
}