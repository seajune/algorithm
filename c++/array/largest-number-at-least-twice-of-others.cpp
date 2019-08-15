/*至少是其他数字两倍的最大数
在一个给定的数组nums中，总是存在一个最大元素 。
查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
如果是，则返回最大元素的索引，否则返回-1。

示例 1:
输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
 
示例 2:
输入: nums = [1, 2, 3, 4]
输出: -1
解释: 4没有超过3的两倍大, 所以我们返回 -1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others
*/

/*思路一
找出最大值和次大值，记录最大值的索引，最大值与次大值的两倍进行比较
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 0){
            return -1;
        }
        if (nums.size() == 1){
            return 0;
        }
        int max = -1;
        int second = -1;
        int index = -1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > max){
                second = max;
                max = nums[i];
                index = i;
            }
            else if(nums[i] > second){
                second = nums[i];
            }
        }
        return max >= 2 * second? index : -1;
    }
};