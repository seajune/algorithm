'''三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
'''

'''
思路一：先排序，在遍历中，在剩余的数组元素中进行首尾的同时遍历。
注意：返回结果中元素不能重复，已经筛选出的元素要略过。
时间复杂度：O(n^2)。
空间复杂度：O(1)。
'''
class Solution:
    def threeSum(self, nums):
        res = []
        nums.sort() #在有序的基础上进行。
        for i in range (len(nums) - 2):
            if nums[i] > 0: #遍历元素大于0时，可以结束遍历了。
                return res
            if i-1 >=0 and nums[i] == nums[i-1]: #遍历相同元素时，只计算一次。
                continue
            start = i + 1
            end = len(nums) - 1
            while start < end:
                if nums[i] + nums[start] + nums[end] == 0:
                    res.append([nums[i], nums[start], nums[end]])
                    start += 1
                    end -= 1
                    while start < end and nums[start] == nums[start - 1]: #遍历相同元素时，只计算一次。
                        start += 1
                    while start < end and nums[end] == nums[end + 1]: #遍历相同元素时，只计算一次。
                        end -= 1
                elif nums[i] + nums[start] + nums[end] > 0:
                    end -= 1
                    while start < end and nums[end] == nums[end + 1]: #遍历相同元素时，只计算一次。
                        end -= 1
                else:
                    start += 1
                    while start < end and nums[start] == nums[start - 1]: #遍历相同元素时，只计算一次。
                        start += 1
        return res