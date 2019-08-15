/*反转链表
反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
*/

/*思路一：迭代
从头遍历，箭头反转
时间复杂度：O(n)
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
    ListNode* reverseList(ListNode* head) { //迭代版本
        ListNode* reversed_head = NULL;
        ListNode* prev = NULL;
        ListNode* now = head;
        ListNode* next = NULL;
        while(now != NULL){
            if (now->next == NULL)
                reversed_head = now;
            next = now->next;
            now->next=prev;
            prev = now;
            now = next;
        }
        return reversed_head;
    }
};

/*思路二：递归
使本节点的下一节点的下一节点改成本节点，原头节点指向NULL
时间复杂度：O(n)
空间复杂度：O(n) （递归，适用了栈空间，栈的深度最高位n）
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
    ListNode* reverseList(ListNode* head) { //递归版本
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* reversed_head = reverseList(head->next);
        head->next->next = head; //将本节点的下节点的下节点改成本节点实行翻转
        head->next = NULL; //断开原连接；使原头节点指向NULL
        return reversed_head;
    }
};