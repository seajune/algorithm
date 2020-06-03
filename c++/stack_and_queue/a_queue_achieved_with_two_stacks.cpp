/*用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
*/

/*
思路一：一个栈用于push，一个栈用于pop。队列：先进先出。栈：先进后出。
插入：时间复杂度：O(1)，空间复杂度：O(1)。
删除：时间复杂度：O(n)，空间复杂度：O(n)。
*/
class CQueue {
public:
    stack<int>stack1;
    stack<int>stack2;
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack2.empty()){
            if(stack1.empty()){
                return -1;
            }
            while(!stack1.empty()){
                int value = stack1.top();
                stack2.push(value);
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }
};
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */