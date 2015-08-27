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
    /** Validate Binary Search Tree
     *  Given a binary tree, determine if it is a valid binary search tree (BST).
     *  Assume a BST is defined as follows:
     *  The left subtree of a node contains only nodes with keys less than the node's key.
     *  The right subtree of a node contains only nodes with keys greater than the node's key.
     *  Both the left and right subtrees must also be binary search trees.
     */

    /***************************************************************
     *  思路：中序遍历的BST是有序的
     *  1）先判断左子树内部是否有序
     *  2）比较前一个节点和当前结点的值
     *  3）后判断右子数内部是否有序
     *  注意：这里最好就保存指针，不要保存节点的值
     *  1）如果节点类型是int，可以赋初值为LLONG_MIN
     *  2）如果节点类型是long long，不好找比其范围更大的数了
     ***************************************************************/
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL;
        return _isValidBST(root, prev);
    }
    bool _isValidBST(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!_isValidBST(node->left, prev)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        return _isValidBST(node->right, prev);
    }

    /***************************************************************
     *  不知道为什么这样就不能通过
     ***************************************************************/
    // bool isValidBST(TreeNode* root) {
    //      static TreeNode * prev = NULL;
    //      if (root == NULL) return true;
    //      if (!isValidBST(root->left)) return false;
    //      if (prev && root->val <= prev->val) {
    //          return false;
    //      }
    //      prev = root;
    //      return isValidBST(root->right);
    // }
    
    /***************************************************************
     *  这里跟上面有同样的问题，还依赖于INT的最小值
     ***************************************************************/
    // bool isValidBST(TreeNode *root) {
    //     static int m = INT_MIN;
    //     if(root == NULL) return true;
    //     if(!isValidBST(root->left)) return false;
    //     if(!(root->val > m)) {
    //         return false;
    //     }
    //     m = root->val;
    //     return isValidBST(root->right);
    // }
};