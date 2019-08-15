/*整数反转
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
*/

/*思路一：正常反转整数的思路
注意：只能存储32位有符号整数，要处理溢出的情况，特别是中间变量，溢出不处理的话，会向上向下溢出，题目要求，溢出取零。
INT32_MAX = INT32_MAX / 10 + INT32_MAX % 10;
res = res * 10 + pop;
时间复杂度：O(log10(x))
空间复杂度：O(1)
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int pop = x % 10;
            if(res > INT32_MAX / 10 || (res == INT32_MAX / 10 && pop > INT32_MAX % 10)) return 0;
            if(res < INT32_MIN / 10 || (res == INT32_MIN / 10 && pop < INT32_MIN % 10)) return 0;
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
};