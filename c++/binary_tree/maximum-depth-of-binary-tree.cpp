/*二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
*/

/*思路一：迭代
迭代，利用队列/栈
时间复杂度：O(n)
空间复杂度：O(n)
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> temp;
        temp.push(pair<TreeNode*, int>(root, 1));
        int depth = 0;
        while(!temp.empty()){
            pair<TreeNode*, int> cur = temp.front();
            depth = cur.second;
            temp.pop();
            if(cur.first->left != NULL)
                temp.push(pair<TreeNode*, int>(cur.first->left, depth+1));
            if(cur.first->right != NULL)
                temp.push(pair<TreeNode*, int>(cur.first->right, depth+1));
        }
        return depth;
    }
};

/*思路二：递归
时间复杂度：O(n)
空间复杂度：O(logn)～O(n) （树的高度）
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};