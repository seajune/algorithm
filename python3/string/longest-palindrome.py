'''最长回文串
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
'''

'''
思路：借助map存储字符的个数，最长回文串长度为字符的最大偶数求和再加一。
时间复杂度：O(n)。
空间复杂度：O(s)。s为字符集大小。
'''
'''
'''
class Solution:
    def longestPalindrome(self, s):
        count_dict = {}
        for i in s:
            if i in count_dict:
                count_dict[i] += 1
            else:
                count_dict[i] = 1
        res = 0
        for i in count_dict:
            res += count_dict[i] // 2 * 2
            if res % 2 == 0 and count_dict[i] % 2 != 0: #个数为奇数的只加一次
                res += 1
        return res

'''
'''
class Solution:
    def longestPalindrome(self, s):
        count_dict = {}
        for i in s:
            if i in count_dict:
                count_dict[i] += 1
            else:
                count_dict[i] = 1
        count = 0
        for i in count_dict:
            count += count_dict[i] % 2 #计算个数为奇数的字符个数
        return len(s) if count == 0 else len(s) - count + 1