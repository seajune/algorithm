/*最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
*/

/*思路一：动态规划法
先遍历出以某个节点为结束节点的所有子序列
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = nums[0];
        for (int i=1; i<nums.size(); ++i){
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            res = max(res, sum);
        }
        return res;
    }
};