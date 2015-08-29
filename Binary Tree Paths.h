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

    /****************************************************************************/
    /*  Given a binary tree, return all root-to-leaf paths.
    /*  For example, given the following binary tree:
    /*            1
    /*          /   \
    /*         2     3
    /*          \
    /*           5
    /*  All root-to-leaf paths are:
    /*  ["1->2->5", "1->3"]
    /****************************************************************************/
    
    /****************************************************************************/
    /*  思路：深度优先
    /*  1）想明白dfs函数的参数哪些该传引用，哪些该传值。一般而言，结果容器传引用，
    /*     中间变量传值
    /*  2）想清楚dfs内部需不需要做非空检查，如果前面不检查root，后面就要检查孩子
    /*  3）处理顺序：根节点->（穿插中间代码）->左子节点->（穿插中间代码）右子节点
    /****************************************************************************/
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root != NULL) {
            string str;
            dfs(root, res, str);
            
        }
        return res;
    }
    
    void dfs(TreeNode * root, vector<string> & res, string str) {
        // 添加上当前节点的值
        str += to_string(root->val);
        if (!root->left && !root->right) { 
            res.push_back(str);
            return ;
        }
		str += "->";
        if (root->left) dfs(root->left, res, str);
        if (root->right) dfs(root->right, res, str);
    }
    
};