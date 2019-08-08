/*寻找数组的中心索引
给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-pivot-index
*/

/*算法一：公式推导
sum_left+sum_right+nums[i]=sum_total ①//其中，nums[i]为中心索引值
sum_left=sum_right ②
②式替换①式得：sum_left=sum_total-nums[i]
只需一次遍历即可
时间复杂度：O(n)
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_total = 0;
        int sum_left = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum_total += nums[i];
        }
        for (int i = 0; i < nums.size(); ++i){
            if (2 * sum_left == sum_total - nums[i]){
                return i;
            }
            sum_left += nums[i];
        }
        return -1;
    }
};