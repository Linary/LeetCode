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

    /*****************************************************************************/
    /*  Given a binary search tree (BST), find the lowest common ancestor (LCA) of 
    /*  two given nodes in the BST.
    /*  “The lowest common ancestor is defined between two nodes v and w as the 
    /*  lowest node in T that has both v and w as descendants (where we allow a 
    /*  node to be a descendant of itself).”
    /*****************************************************************************/
    
    /*****************************************************************************/
    /*  思路：
    /*  1）如果该树是BST，从根节点开始遍历，如果根节点值大于两个节点，则往左子树移动
    /*     如果根节点的值小于两个节点，则往右子树移动，否则根节点就是最低公共祖先
    /*  2）如果该树有指向父节点的指针，则可以转化为求链表第一个公共节点的问题
    /*  3）如果只是普通的二叉树，则需要通过两次遍历得到两个链表，再求解链表公共节点
    /*****************************************************************************/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ((root->val - p->val) * (root->val - q->val) > 0)
            root = p->val < root->val ? root->left : root->right;
        return root;
    }
};