'''整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
'''

'''
思路一：除，取模。注意，反转后的数据不能溢出。
时间复杂度：O(lgn)。
空间复杂度：O(1)。
参考：https://leetcode-cn.com/problems/reverse-integer/solution/tu-jie-7-zheng-shu-fan-zhuan-by-wang_ni_ma/
'''
class Solution:
    def reverse(self, x):
        res = 0
        while x != 0:
            if x < 0: #注意python负数除和取模
                tmp = -((-x) % 10)
                x = -((-x) // 10)
            else:
                tmp = x % 10
                x //= 10
            if res > 214748364 or res == 214748364 and tmp > 7:
                return 0
            if res < -214748364 or res == -214748364 and tmp < -8:
                return 0
            res = res * 10 + tmp
        return res