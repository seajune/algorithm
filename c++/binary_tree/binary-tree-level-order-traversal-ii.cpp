/* 二叉树的层次遍历 II(自底向上层次遍历)
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：
[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
*/

/*思路一：迭代：层次遍历+反转
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> temp;
            int depth = que.size();
            for(int i=0; i<depth; ++i){
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end()); //层次遍历的结果反转
        return res;
    }
};

/*思路二：递归：层次遍历+反转
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        pre(root, 0, res);
        reverse(res.begin(), res.end()); //层次遍历的结果反转
        return res;
    }
    
    void pre(TreeNode* cur, int depth, vector<vector<int>> &res){
        if(!cur)
            return;
        if(depth >= res.size())
            res.push_back(vector<int> {});
        res[depth].push_back(cur->val);
        pre(cur->left, depth+1, res);
        pre(cur->right, depth+1, res);
    }
};