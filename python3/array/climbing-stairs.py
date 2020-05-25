'''爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
'''

'''
思路一：斐波那契数列，迭代法。
时间复杂度：O(n)。
空间复杂度：O(1)。
'''
class Solution:
    def climbStairs(self, n):
        if n <= 2:
            return n
        i1 = 1
        i2 = 2
        for i in range(3, n+1):
            res = i2 + i1
            i1 = i2
            i2 = res
        return res