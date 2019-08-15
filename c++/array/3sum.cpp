/*三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
*/

/*思路一：先排序，再遍历，定义首尾指针
先排序，再遍历，定义首尾指针，三数求和与0比较，大于0，则尾指针减一；小于零，则首指针加一；等于零，则首尾分别加减一
注意：
1、首元素大于0或者尾元素小于0时，不满足条件，返回
2、遍历的元素如果大于0，结束遍历
3、相邻元素有重复的，不计入
时间复杂度：O(n^2)
空间复杂度：O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        if (nums[0] >0 || nums[nums.size()-1] < 0) //首元素大于0或者尾元素小于0时，不满足条件，返回
            return res;
        for (int i=0; i<nums.size()-1; ++i){
            if (nums[i] > 0) break; //遍历的元素如果大于0，结束遍历
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i]+nums[left]+ nums[right];
                if (sum == 0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left-1]) ++left; //相邻元素有重复的，不计入
                    while (left < right && nums[right] == nums[right+1]) --right; //相邻元素有重复的，不计入
                    
                }
                else if(sum > 0){
                    --right;
                    while (left < right && nums[right] == nums[right+1]) --right; //相邻元素有重复的，不计入
                }
                else if(sum < 0){
                    ++left;
                    while (left < right && nums[left] == nums[left-1]) ++left; //相邻元素有重复的，不计入
                }  
            }
        }
        return res;
    }
};