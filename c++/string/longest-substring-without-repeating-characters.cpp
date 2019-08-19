/*无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
*/

/*滑动窗口
时间复杂度：O(n)
空间复杂度：O(min(n,m))
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        map<char, int> temp;
        int len = 0;
        for(int start=0, end=0; end < s.size(); ++end){
            if(temp.find(s[end]) != temp.end()){
                start = max(start, temp[s[end]]);
                temp[s[end]] = end+1; //取下标才会覆盖
            }
            else{
                temp.insert(pair<char, int>(s[end], end+1)); //insert不会覆盖，取下标才会覆盖
            }
            len = max(len, end-start+1);
        }
        return len;
    }
};