/*二叉树的层次遍历   
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
*/

/*思路一：迭代
迭代，先进先出，借助队列
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> temp;
            int len = que.size();
            for(int i=0; i < len; ++i){
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
        return res;
    }
};

/*思路二：递归
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        pre(root, 0, res);
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