/*有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
*/

/*思路一：利用栈
利用栈的性质，先进后出，遇到左括号则入栈，遇到右括号则与栈顶元素匹配，若匹配成功则将栈顶元素弹出，否则返回false。
map存储开括号和闭括号的对应关系。
时间复杂度：O(n)
空间复杂度：O(n)  (栈的深度)
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        map <char, char> mapping;
        mapping.insert(pair<char,char>(')', '('));
        mapping.insert(pair<char,char>('}', '{'));
        mapping.insert(pair<char,char>(']', '['));
        stack<char> res;
        for (int i = 0; i < s.size(); ++i){
            if (mapping.find(s[i]) != mapping.end()){ //右括号跟栈顶比较
                if (res.empty()) return false;
                if (mapping[s[i]] != res.top())
                    return false;
                res.pop();
            }
            else{
                res.push(s[i]); //左括号入栈
            }
        }
        if (res.empty())
            return true;
        else
            return false;
                       
    }
};