'''回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
'''

'''
思路一：通过取整和取余操作获取整数中对应的数字进行比较。
好处：不需要考虑整数溢出的问题。
时间复杂度：O(lgn)。
空间复杂度：O(1)。
'''
class Solution:
    def isPalindrome(self, x):
        if x >= 0 and x <= 9:
            return True
        if x < 0:
            return False
        div = 1
        while(x // div >= 10):
            div *= 10
        while x != 0:
            left = x // div
            right = x % 10
            if left != right:
                return False
            x = x % div // 10
            div //= 100
        return True
    
'''
思路二：将数字进行对折后看能否一一对应，即取出后半段数字进行翻转。
注意：注意数据为10的倍数时。
时间复杂度：O(lgn)。
空间复杂度：O(1)。
'''
class Solution:
    def isPalindrome(self, x):
        if x < 0 or x % 10 == 0 and x // 10 != 0:
            return False
        res = 0
        while (x > res):
            res = res * 10 + x % 10
            x //= 10
        return x == res or x == res // 10

'''
思路三：将整数转为字符串。反转字符串，跟原字符串比较。
'''
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        tmp = str(x)
        reverse = tmp[::-1]
        return tmp == reverse

'''
思路四：将整数转为字符串。字符串首尾相应位数进行比较。
'''
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        tmp = str(x)
        i = 0
        j = len(tmp)-1
        while(i < j):
            if tmp[i] != tmp[j]:
                return False
            i += 1
            j -= 1
        return True