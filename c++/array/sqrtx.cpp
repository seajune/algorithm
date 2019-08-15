/*x 的平方根
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
*/

/*思路一：常规思路，遍历到x为止
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int mySqrt(int x) {
        long i = 0;
        while(i <= x && i * i <= x){
            i++;
        }
        int res = i - 1;
        return res;
    }
};

/*思路二：二分法
时间复杂度：O(logn)
空间复杂度：o(1)
*/
class Solution {
public:
    int mySqrt(int x) {
        long i = 0;
        long j = x/2 + 1; //还有待理解
        while(i <= j){
            long mid = (i+j)/2;
            long res = mid * mid;
            if (res == x) return mid;
            else if (res > x) j = mid - 1;
            else i = mid + 1;
        }
        return j;
    }
};

/*思路三：牛顿迭代法（没理解，待定）
*/