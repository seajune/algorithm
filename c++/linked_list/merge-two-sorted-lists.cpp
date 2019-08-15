/*合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
*/

/*思路一：迭代
时间复杂度：O(m+n)
空间复杂度：O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0); //new新开辟定义的数据结构类型的内存，head指针指向这块内存
        ListNode *now = head;
        while(l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                now->next = l1;
                l1 = l1->next;
            }
            else{
                now->next = l2;
                l2 = l2->next;
            }
            now = now->next;
        }
        now-> next = l1 == NULL ? l2:l1;
        ListNode * merge_head = head->next;
        delete head; //动态申请的内存要释放，避免内存泄漏
        return merge_head;
    }
};

/*思路二：递归
时间复杂度：O(m+n)
空间复杂度：O(m+n)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { 
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if (l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2); //l1链接排好序的链表
            return l1; //返回链接头节点
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next); //l2链接排好序的链表
            return l2; //返回链接头节点
        }
    }
};