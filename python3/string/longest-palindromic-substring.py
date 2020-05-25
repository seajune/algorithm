'''最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
'''

'''
思路一：中心扩展法，回文子串长度为奇数、偶数时分别考虑。
时间复杂度：O(n^2)。
空间复杂度：O(1)。
'''
class Solution:
    def longestPalindrome(self, s):
        if len(s) <= 1:
            return s
        start = 0
        length = 0
        for i in range(len(s)):
            length1 = self.lengthPalindrome(s, i-1, i+1)
            length2 = self.lengthPalindrome(s, i, i+1)
            if max(length1, length2) > length:
                length = max(length1, length2)
                start = i - (length-1) // 2
        return s[start:start+length]

    def lengthPalindrome(self, s, left, right):
        while left >= 0 and right <= len(s)-1 and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1