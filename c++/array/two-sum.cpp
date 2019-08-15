/*两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum

/*思路一：暴力法
时间复杂度：O(n^2)
空间复杂度：O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i=0; i<nums.size()-1; ++i){
            for (int j=i+1; j<nums.size(); ++j){
                if (nums[i] == target-nums[j]){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

/*思路二：一遍哈希法
哈希存储数据和索引，把时间复杂度转移到空间复杂度
时间复杂度：O(n)
空间复杂度：O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> temp;
        for (int i=0; i<nums.size(); ++i){
            if (temp.find(target-nums[i]) != temp.end()){
                res.push_back(temp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            temp.insert(pair<int,int>(nums[i],i));
        }
        return res;
    }
};