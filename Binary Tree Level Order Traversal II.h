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
    
    /**************************************************************************/
    /*  Given a binary tree, return the bottom-up level order traversal of 
    /*  its nodes' values. (ie, from left to right, level by level from leaf to root).
    /*  For example:
    /*  Given binary tree {3,9,20,#,#,15,7},
    /*        3
    /*       / \
    /*      9  20
    /*        /  \
    /*       15   7
    /*  return its bottom-up level order traversal as:
    /*  [
    /*  [15,7],
    /*  [9,20],
    /*  [3]
    /*  ]
    /**************************************************************************/
    
    /**************************************************************************/
    /*  思路：深度优先遍历 + 反向输出
    /**************************************************************************/
    void DFS(TreeNode* root, vector<vector<int> > & res, int level) {
        if (root == NULL) return;
        // 如果当前层不存在，创建
        if (level == res.size()) {
            res.push_back(vector<int>()); 
        }
    
        // 把当前元素添加到当前层的vector
        res[level].push_back(root->val); 
        // 继续下一层
        DFS(root->left, res, level + 1); 
        DFS(root->right, res, level + 1);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        DFS(root, res, 0);
        // 逆序打印结果
        return vector<vector<int> > (res.rbegin(), res.rend());
    }
};