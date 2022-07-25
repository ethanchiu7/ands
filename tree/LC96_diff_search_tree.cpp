//
//  LC96_diff_search_tree.cpp
//  https://leetcode.cn/problems/unique-binary-search-trees/
//  给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
//  Created by didi on 7/25/22.
//
//示例 1：
//输入：n = 3
//输出：5

//示例 2：
//输入：n = 1
//输出：1
//
//提示：
//
//1 <= n <= 19

#include <stdio.h>

class Solution {
public:
    int numTrees(int n) {
        int dp[20];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int curr_num = 0;
            for (int j = 0; j <= i - 1; j++) {
                if (j == 0 || i - 1 - j == 0) {
                    curr_num = curr_num + max(dp[i - 1 - j], dp[j]);
                } else {
                    curr_num = curr_num + dp[j] * dp[i - 1 - j];
                }
                
            }
            dp[i] = curr_num;
        }
        return dp[n];

    }
};

