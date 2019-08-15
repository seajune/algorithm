/*回文数
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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
*/

/*思路一：逐位比较
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int len = 1;
        while(x / len >= 10)
            len *= 10;
        while(x > 0){
            int left = x / len;
            int right = x % 10;
            if (left != right)
                return false;
            x = x % len / 10; //去掉left和right元素
            len /= 100; //去掉了两个元素
        }
        return true;
    }
};

/*思路二：数字全部翻转
翻转数字，与原数字比较
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long res = 0;
        long divide = x;
        while(divide > 0){
            res = res * 10 + divide % 10;
            divide /= 10;
        }
        return x == res;
    }
};

/*思路三：数字一半翻转
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x !=0 && x % 10 == 0) //要考虑末尾有0的情况，如：10，不满足下面的循环，单独拿出来讨论
            return false; 
        int reverse = 0;
        while(x > reverse){
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == x || reverse / 10 == x; //如输入的x为奇数位，则此时reverse比x多一位（中间位）
    }
};

/*思路四：转换为字符串
转换为字符串，首尾两指针比较字符
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string temp;
        temp = to_string(x);
        int i = 0;
        int j = temp.size()-1;
        while(i < j){
            if (temp[i] != temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};