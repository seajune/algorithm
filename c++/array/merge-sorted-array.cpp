/*合并两个有序数组
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
*/

/*思路一：双指针从头遍历
复制一份nums1，复制数组和nums2双指针从头遍历，插入nums1中
时间复杂度：O(m+n)
空间复杂度：O(m)
总结：空间复杂度较高，超出内存限制!!
*/
/*
pass
*/

/*思路二：双指针头尾遍历
双指针头尾遍历，从nums1（m+n+1）内存依次往前插入
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0){
            if (nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j >= 0){
            nums1[j] = nums2[j]; //nums2剩余元素直接复制过去
            j--;
        }
    }
};