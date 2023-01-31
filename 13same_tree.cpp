// https://leetcode.com/problems/same-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        if(p!=NULL)q1.push(p);
        if(q!=NULL)q2.push(q);
        while((!q1.empty())&&(!q2.empty())) {
            TreeNode *first = q1.front();
            TreeNode *second = q2.front();
            q1.pop();
            q2.pop();
            if(first->val!=second->val) return false;
            if(first->left==NULL || second->left==NULL) {
                if(first->left!=second->left) return false;
            } else {
                q1.push(first->left);
                q2.push(second->left);
            }

            if(first->right==NULL || second->right==NULL) {
                if(first->right!=second->right) return false;
            } else {
                q1.push(first->right);
                q2.push(second->right);
            }
        }
        return (q1.empty() && q2.empty());
    }
};