/* 二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：
[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
*/

/*思路一：迭代
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        int width = 0;
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
            if(width % 2 == 1)
                reverse(temp.begin(), temp.end());
            res.push_back(temp);
            width += 1;
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        pre(root, 0, res);
        return res;
    }
    
    void pre(TreeNode* cur, int depth, vector<vector<int>> &res){
        if(!cur)
            return;
        if(depth >= res.size())
            res.push_back(vector<int>{});
        if(depth%2 == 0){
            res[depth].push_back(cur->val);
        }
        else{
            res[depth].insert(res[depth].begin(), cur->val);
        }
        pre(cur->left, depth+1, res);
        pre(cur->right, depth+1, res);
    }
};