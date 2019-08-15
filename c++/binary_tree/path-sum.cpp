/*路径总和
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
*/

/*思路一：迭代
利用栈，遍历到叶子结点且路径和等于目标值，才返回true。
时间复杂度：O(n) （每个子节点都要遍历）
空间复杂度：当树不平衡的最坏情况下是O(n)；在最好情况（树是平衡的）下是O(logn)。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        stack<TreeNode *> temp;
        temp.push(root);
        while(!temp.empty()){
            TreeNode* node = temp.top();
            temp.pop();
            if(node->left == NULL && node->right == NULL && node->val == sum)
                return true;
            if(node->left != NULL){
                node->left->val += node->val;
                temp.push(node->left);
            }
            if(node->right != NULL){
                node->right->val += node->val;
                temp.push(node->right);
            }   
        }
        return false;
    }
};

/*思路二：递归
时间复杂度：O(n)
空间复杂度：树倾斜时，为O(n)；树平衡时，为O(logn)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        sum -= root->val;
        if(root->left == NULL && root->right == NULL)
            return sum == 0;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};