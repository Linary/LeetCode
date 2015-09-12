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
    /*  Given a binary tree, return the level order traversal of its nodes' values.
    /*  (ie, from left to right, level by level).
    /*  For example:
    /*  Given binary tree {3,9,20,#,#,15,7},
    /*           3
    /*          / \
    /*         9  20
    /*           /  \
    /*          15   7
    /*  return its level order traversal as:
    /*  [
    /*   [3],
    /*   [9,20],
    /*   [15,7]
    /*  ]
    /*****************************************************************************/

    /*****************************************************************************/
    /*  思路：
    /*  1）使用一个辅助递归函数——FillContainer
    /*  2）该函数参数包括当前结点，结果容器，层编号
    /*  3）如果结果容器中还没有该层，则追加一层
    /*  4）添加当前结点至容器，并对左子树和右子数重复该操作
    /*****************************************************************************/
    vector<vector<int> > levelOrder(TreeNode * root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        int level = 0;
        FillContainer(root, result, level);
        return result;
    }
    
    
    void FillContainer(TreeNode * node, vector<vector<int> > & result, int level) {
        if (result.size() < level + 1) {
            result.push_back(vector<int>());
        }
        
        result[level].push_back(node->val);
        if (node->left) {
            FillContainer(node->left, result, level + 1);
        } 
        if (node->right) {
            FillContainer(node->right, result, level + 1);
        } 
    }
};