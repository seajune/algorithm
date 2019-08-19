/*最长回文子串
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
*/

/*思路一：中心扩展法
中心扩展法，回文子串长度为奇数、偶数时分别考虑
时间复杂度：O(n^2)
空间复杂度：O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 1)
            return s;
        int max_len=0;
        int start = 0;

        for(int i=0;i<s.size();i++)
        {
            int len1 = expandAroundCenter(s, i-1, i+1); //回文子串长度为奇数时
            int len2 = expandAroundCenter(s, i, i+1); //回文子串长度为偶数时
            if (max(len1,len2) > max_len){
                max_len = max(len1,len2);
                start = i-(max_len-1)/2;
            }
        }
        return s.substr(start, max_len); 
    }
    
    int expandAroundCenter(string s, int left, int right){
        int l=left, r=right;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    
};