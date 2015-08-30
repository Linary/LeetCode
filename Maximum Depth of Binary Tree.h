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
    
    /***********************************************************************/
    /*  Given a binary tree, find its maximum depth.
    /*  The maximum depth is the number of nodes along the longest path from 
    /*  the root node down to the farthest leaf node.
    /***********************************************************************/
    
    /***********************************************************************/
    /*  思路：
    /*  1）当前节点为空，fan'hui返回 0
    /*  2）当前结点不为空，返回左右子树深度较大 + 1
    /***********************************************************************/
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};