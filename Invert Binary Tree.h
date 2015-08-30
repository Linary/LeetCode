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
    
    /*****************************************************************/
    /*  翻转二叉树，左右互换
    /*****************************************************************/
    
    /*****************************************************************/
    /*  思路：
    /*  1）递归：分别翻转左子树，再交换左右两个子节点
    /*  2）迭代：把左右子节点指针存入栈，交换它们的值，深度优先重复操作
    /*****************************************************************/
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
    

    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode * p = stk.top();
            stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }
};