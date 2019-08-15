/*回文链表
请判断一个链表是否为回文链表。

示例 1:
输入: 1->2
输出: false

示例 2:
输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
*/

/*思路一：反转链表后半段，待定！！（提交错误，待查原因）
利用快慢指针，反转链表后半段
时间复杂度：O(1.5n)≈O(n)
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(slow != NULL){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode* p = head;
        ListNode* q = prev;
        while(p != NULL && q != NULL){
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

/*思路二：反转链表前半段
利用快慢指针，快慢指针遍历的同时反转链表前半段
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
class Solution { //待定！！（提交错误，待查原因）
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        ListNode* prepre = NULL;
        if(fast && fast->next){
            pre  = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }
        ListNode* p = prepre;
        ListNode* q = fast == NULL ? slow:slow->next;
        while(p){
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { //提交正确
public:
    bool isPalindrome(ListNode* head) {
   	    if(head == NULL || head->next == NULL) return true;
    	ListNode* slow = head, *fast = head->next, *pre = NULL, *prepre = NULL;
    	while(fast != NULL && fast->next != NULL) {
    		//反转前半段链表
    		pre = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    		//先移动指针再来反转
    		pre->next = prepre;
    		prepre = pre;
    	}
    	ListNode* p2 = slow->next;
    	slow->next = pre;
    	ListNode* p1 = fast == NULL? slow->next : slow;
    	while(p1 != NULL) {
    		if(p1->val != p2->val)
    			return false;
    		p1 = p1->next;
    		p2 = p2->next;
    	}
		return true;
    }
};