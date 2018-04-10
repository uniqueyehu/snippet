#include <iostream>
#include <cstdio>

#include <vector>
#include <string>

#include <stack>
#include <queue>

#include <map>
#include <unordered_map>


using namespace std;

/*
 0-1 背包问题：给定 n 种物品和一个容量为 C 的背包，物品 i 的重量是 wi，其价值为 vi 。
 问：应该如何选择装入背包的物品，使得装入背包中的物品的总价值最大？

 dp[i][j]表示在面对第i件物品，且背包容量为j时所能获取的最大价值
 dp[i][j] = max{dp[i-1][j], dp[i-1][j - w[i]] + v[i]}
*/

const int N = 15;
int dp[N][N];   // 初始化全为0

void knap(void)
{
    int v[N] = {0, 8, 10, 6, 3, 7, 2};  // 每件物品的价值
    int w[N] = {0, 4, 6, 2, 2, 5, 1};   // 每件物品的重量
    int n = 6, m = 12;  // 物品个数和背包容量

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j >= w[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // 输出二维矩阵
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%2d ", dp[i][j]);
        printf("\n");
    }

    // 找到最优解
    int c = m;
    int x[N] = {0};
    for (int i = n; i > 1; --i)
    {
        if (dp[i][c] == dp[i-1][c])
            x[i] = 0;
        else
        {
            x[i] = 1;
            c -= w[i];
        }
    }
    x[1] = (dp[1][c] > 0) ? 1 : 0;
    for (int i = 1; i <= n; ++i)
        printf("%2d", x[i]);

}
